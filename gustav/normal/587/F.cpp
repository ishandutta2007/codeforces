#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 100005;
const int MAXA = 26;

struct Node {
  int cnt;
  int rev;
  Node *f, *fc, *sib;
  Node *c[MAXA];

  void clear() {
    f = fc = sib = 0;
    cnt = rev = 0;
    memset(c, 0, sizeof c);
  }
};

Node mem[3 * MAXN];
Node *alloc = mem;

void reset() {
  alloc = mem;
}

Node *make_node() {
  Node *ret = alloc++;
  ret->clear();
  return ret;
}

struct AhoCorasick {
  Node *root;

  AhoCorasick() {
    root = make_node();
  }

  void add(string &s) {
    Node *it = root;
    int n = s.length();

    REP(i, n) {
      int c = s[i] - 'a';
      if (!it->c[c])
	it->c[c] = make_node();
      it = it->c[c];
    }

    it->cnt += 1;
  }

  void init() {
    queue< Node* > q;
    root->f = root;

    REP(i, MAXA) {
      if (!root->c[i]) continue;
      root->c[i]->f = root;
      root->c[i]->sib = root->fc;
      root->fc = root->c[i];
      q.push(root->c[i]);
    }

    while (!q.empty()) {
      Node *n = q.front(); q.pop();

      REP(i, MAXA) {
	if (!n->c[i]) continue;

	Node *c = n->c[i];
	c->f = n->f;
	while (c->f != root && !c->f->c[i])
	  c->f = c->f->f;

	if (c->f->c[i]) c->f = c->f->c[i];
	c->sib = c->f->fc;
	c->f->fc = c;

	c->cnt += c->f->cnt;

	q.push(c);
      }
    }
  }

  int eat(string &s) {
    Node *it = root;
    int n = s.length();
    int sol = 0;

    REP(i, n) {
      int c = s[i] - 'a';
      while (it != root && !it->c[c])
	it = it->f;
      if (it->c[c]) it = it->c[c];
      sol += it->cnt;
      it->rev += 1;
    }

    return sol;
  }

  void rec(Node *it) {
    for (Node *jt = it->fc; jt; jt = jt->sib) {
      rec(jt);
      it->rev += jt->rev;
    }
  }

  void process_rev() {
    rec(root);
  }

  void clear(Node *it) {
    it->rev = 0;
    for (Node *jt = it->fc; jt; jt = jt->sib)
      clear(jt);
  }

  void clear_rev() {
    clear(root);
  }

  int get_rev_matches(string &s) {
    Node *it = root;
    int n = s.length();

    REP(i, n) {
      int c = s[i] - 'a';
      it = it->c[c];
    }

    return it->rev;
  }
};

const int MAGIC = 330;

struct Query {
  int id;
  int l, r;
};

int N, M;
llint bcnt[MAXN];
llint cnt[MAXN];
llint sol[MAXN];
vector< Query > qs[MAXN];
string s[MAXN];
int b[MAXN];

int id[MAXN];
int l[MAXN];
int r[MAXN];

void solve() {
  b[0] = b[N] = 1;
  int ccnt = 0;

  REP(i, N) {
    if (ccnt + s[i].length() > MAGIC) {
      ccnt = s[i].length();
      b[i] = 1;
    } else {
      ccnt += s[i].length();
    }
  }

  reset();
  AhoCorasick ac_all;
  REP(i, N) ac_all.add(s[i]);
  ac_all.init();

  for (int i = 0, j; i < N; i = j) {
    for (j = i + 1; !b[j]; ++j);

    if (s[i].length() > MAGIC) { // solo
      ac_all.eat(s[i]);
      ac_all.process_rev();

      REP(j, N) cnt[j] = ac_all.get_rev_matches(s[j]);
      FOR(j, 1, N) cnt[j] += cnt[j - 1];

      for (auto q : qs[i]) {
	llint ccnt = cnt[q.r];
	if (q.l) ccnt -= cnt[q.l - 1];
	sol[q.id] += cnt[q.r];
	if (q.l) sol[q.id] -= cnt[q.l - 1];
      }

      ac_all.clear_rev();
    } else {
      AhoCorasick ac_local;
      FOR(k, i, j) ac_local.add(s[k]);
      ac_local.init();

      int ls = 0;
      FOR(k, i, j) ls += s[k].length();

      REP(k, N) {
	if (s[k].length() > MAGIC) continue;
	bcnt[k] = ac_local.eat(s[k]);
      }

      REP(k, M) {
	if (s[id[k]].length() > MAGIC) continue;
	if (!(l[k] <= i && j - 1 <= r[k])) continue;
	sol[k] += bcnt[id[k]];
      }
    }
  }

  REP(i, M) {
    if (s[id[i]].length() > MAGIC) continue;

    reset();
    AhoCorasick ac;
    int j = l[i];
    while (j <= r[i] && !b[j]) {
      ac.add(s[j++]);
    }
    if (j <= r[i]) {
      j = r[i];
      while (!b[j + 1]) {
	ac.add(s[j--]);
      }
    }
    ac.init();

    sol[i] += ac.eat(s[id[i]]);
  }
}

int main(void) 
{
  cin >> N >> M;
  REP(i, N) cin >> s[i];
  REP(i, M) {
    cin >> l[i] >> r[i] >> id[i];
    --l[i];
    --r[i];
    --id[i];

    qs[id[i]].push_back({i, l[i], r[i]});
  }

  solve();

  REP(i, M)
    printf("%lld\n", sol[i]);

  return 0;
}