#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-12;
const ld pi = acos(-1.0L); 

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

void precalc() {
}

struct Corasick {
  const int alpha = 26;
  vector<vector<int> > go;
  vector<int> term, link;
  vector<int> ends;

  int root;

  Corasick() {
    root = 0;
    go.pb(vector<int> (alpha, -1));
    term.pb(-1), link.pb(-1);
    ends.pb(0);
  }

  int add(char * s, int len) {
    int cur = root;
    for (int i = 0; i < len; i++) {
      int & nxt = go[cur][s[i] - 'a'];
      if (nxt == -1) {
        nxt = sz(go);
        go.pb(vector<int> (26, -1));
        term.pb(-1), link.pb(-1);
        ends.pb(0);
      }
      cur = nxt;
    }
    term[cur] = cur;
    ends[cur]++;
    return cur;
  }

  void bfs() {
    queue<int> q;
    for (int i = 0; i < alpha; i++) {
      int & cur = go[root][i];
      if (cur == -1) {
        cur = 0;
      } else {
        q.push(cur);
        link[cur] = 0;
      }
    }
    while (sz(q)) {
      int cur = q.front();
      q.pop();
      if (term[cur] == -1) {
        term[cur] = term[link[cur]];
      }
      for (int i = 0; i < alpha; i++) {
        int & nxt = go[cur][i];
        if (nxt == -1) {
          nxt = go[link[cur]][i];
        } else {
          q.push(nxt);
          link[nxt] = go[link[cur]][i];
        }
      }
    }
  }

  vector<int> cnt;
  vector<int> toclear;

  ll solve(char * s, int len) {
    ll res = 0;
    cnt.resize(sz(go));
    for (int i = 0; i < sz(toclear); i++) {
      cnt[toclear[i]] = 0;
    }
    toclear.clear();
    for (int i = 0, cur = root; i < len; i++) {
      cur = go[cur][s[i] - 'a'];
      for (int j = term[cur]; j != -1; j = term[link[j]]) {
        res += ends[j];
        cnt[j]++;
        toclear.pb(j);
      }
    }
    return res;
  }
};

const int maxn = 3e5;
const int inblock = 300;
int n, q;
char str[maxn];
char *curbegin;
char *s[maxn];
int len[maxn];
vector<vector<pair<int, int> > > queries;
vector<vector<int> > qid;

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  curbegin = str;
  for (int i = 0; i < n; i++) {
    scanf("%s", curbegin);
    s[i] = curbegin;
    len[i] = strlen(curbegin);
    curbegin += len[i] + 1;
  }
  queries = vector<vector<pair<int, int> > > (n);
  qid = vector<vector<int> > (n);
  for (int i = 0; i < q; i++) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    l--, k--;
    queries[k].eb(l, r);
    qid[k].eb(i);
  }
  return true;
}

void solve() {
  Corasick all;
  vector<Corasick> blocks;
  vector<int> where(n);
  for (int i = 0; i < n; ) {
    blocks.pb(Corasick());
    for (int j = 0; j < inblock && i < n; i++, j++) {
      blocks.back().add(s[i], len[i]);
      where[i] = all.add(s[i], len[i]);
    }
    blocks.back().bfs();
  }
  all.bfs();
  vector<ll> ans(q);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (n + inblock - 1) / inblock; j++) {
      int curl = j * inblock, curr = curl + inblock;
      ll res = blocks[j].solve(s[i], len[i]);
      all.solve(s[i], len[i]);
      for (int it = 0; it < sz(queries[i]); it++) {
        int l = queries[i][it].first, r = queries[i][it].second;
        if (l <= curl && curr <= r) {
          ans[qid[i][it]] += res;
        } else {
          for (int a = max(l, curl); a < min(r, curr); a++) {
            ans[qid[i][it]] += all.cnt[where[a]];
          }
        }
      }
    }
  }
  for (int i = 0; i < q; i++) {
    printf(LLD "\n", ans[i]);
  }
}

int main() {
  srand(rdtsc());
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}