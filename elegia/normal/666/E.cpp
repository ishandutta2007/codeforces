#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

#define fir first
#define sec second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

ostream &operator<<(ostream &os, const pair<char, int> &unit) {
  return os << unit.first << "^" << unit.second;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int Q = 500010, M = 50010, A = 26;

namespace SAM {

int root, top;

int ch[M * 2][A];
int fail[M * 2], len[M * 2];

void init() {
  root = ++top;
}

int extend(int o, int c) {
  int p = ++top;
  len[p] = len[o] + 1;

  while (o && !ch[o][c]) {
    ch[o][c] = p;
    o = fail[o];
  }
  if (!o) {
    fail[p] = root;
  } else {
    int q = ch[o][c];
    if (len[q] == len[o] + 1) {
      fail[p] = q;
    } else {
      int nq = ++top;
      memcpy(ch[nq], ch[q], sizeof(int) * A);
      fail[nq] = fail[q];
      len[nq] = len[o] + 1;

      fail[q] = fail[p] = nq;
      while (o && ch[o][c] == q) {
        ch[o][c] = nq;
        o = fail[o];
      }
    }
  }
  return p;
}

}

namespace TRIE {

int root, top;
int ch[M][A];

void init() {
  root = ++top;
}

int ins(int o, int c) {
  if (!ch[o][c]) ch[o][c] = ++top;
  return ch[o][c];
}

void bfs() {
  queue<pair<int, int>> q;
  q.emplace(root, SAM::root);
  while (!q.empty()) {
    int o, so;
    tie(o, so) = q.front();
    q.pop();
    for (int i = 0; i < A; ++i)
      if (ch[o][i])
        q.emplace(ch[o][i], SAM::extend(so, i));
  }
}

}

namespace SEG {

const int LG = 20, POL = M * LG * 4;

int top;
int ls[POL], rs[POL];
pii val[POL];

void upd(int o) {
  val[o] = max(val[ls[o]], val[rs[o]]);
}

int ins(int o, int l, int r, int k) {
  if (!o) o = ++top;
  if (l == r) {
    ++val[o].fir;
    val[o].sec = -k;
    return o;
  }
  int mid = (l + r) >> 1;
  if (k <= mid)
    ls[o] = ins(ls[o], l, mid, k);
  else
    rs[o] = ins(rs[o], mid + 1, r, k);
  upd(o);
  return o;
}

int merge(int x, int y, int l, int r) {
  if (!x) return y;
  if (!y) return x;
  if (l == r) {
    val[x].fir += val[y].fir;
    return x;
  }
  int mid = (l + r) >> 1;
  ls[x] = merge(ls[x], ls[y], l, mid);
  rs[x] = merge(rs[x], rs[y], mid + 1, r);
  upd(x);
  return x;
}

pii query(int o, int l, int r, int ql, int qr) {
  if (!o) return pii(0, 0);
  if (ql == l && qr == r) return val[o];
  int mid = (l + r) >> 1;
  if (qr <= mid) return query(ls[o], l, mid, ql, qr);
  if (ql > mid) return query(rs[o], mid + 1, r, ql, qr);
  return max(query(ls[o], l, mid, ql, mid), query(rs[o], mid + 1, r, mid + 1, qr));
}

}

int m;
pii ans[Q];
string s, t[M];
vector<tuple<int, int, int>> query[M * 2];

namespace TREE {

const int L = 19;

int n;
int seg[M * 2];
int prt[M * 2][L];
vector<int> ch[M * 2];

int jump(int o, int k) {
  for (int j = L - 1; j >= 0; --j)
    if (SAM::len[prt[o][j]] >= k)
      o = prt[o][j];
  return o;
}

void pre() {
  n = SAM::top;
  for (int i = 2; i <= n; ++i) {
    prt[i][0] = SAM::fail[i];
    ch[SAM::fail[i]].push_back(i);
  }
  function<void(int)> dfs = [&](int u) {
    for (int j = 1; j < L; ++j) prt[u][j] = prt[prt[u][j - 1]][j - 1];
    for (int v : ch[u])
      dfs(v);
  };
  dfs(1);
}

void getans() {
  for (int i = 1; i <= m; ++i) {
    int o = 1;
    for (char c : t[i]) {
      o = SAM::ch[o][c - 'a'];
      seg[o] = SEG::ins(seg[o], 1, m, i);
    }
  }
  function<void(int)> dfs = [&](int u) {
    for (int v : ch[u]) {
      dfs(v);
      seg[u] = SEG::merge(seg[u], seg[v], 1, m);
    }
    for (const auto& tup : query[u]) {
      int l, r, id;
      tie(l, r, id) = tup;
      auto res = SEG::query(seg[u], 1, m, l, r);
      if (res.fir)
        ans[id] = res;
    }
  };
  dfs(1);
}

}

int pos[Q], cur[Q];

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  SAM::init();
  TRIE::init();

  cin >> s >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> t[i];
    int o = TRIE::root;
    for (char c : t[i])
      o = TRIE::ins(o, c - 'a');
  }
  TRIE::bfs();
  TREE::pre();

  {
    int o = 1, n = s.length(), tmp = 0;
    for (int i = 1; i <= n; ++i) {
      int c = s[i - 1] - 'a';
      while (o != 1 && !SAM::ch[o][c]) {
        o = SAM::fail[o];
        tmp = SAM::len[o];
      }
      if (SAM::ch[o][c]) {
        o = SAM::ch[o][c];
        ++tmp;
      }
      cur[i] = tmp;
      pos[i] = o;
    }
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int l, r, pl, pr;
    cin >> l >> r >> pl >> pr;
    ans[i].sec = -l;
    if (cur[pr] >= pr - pl + 1) {
      int o = TREE::jump(pos[pr], pr - pl + 1);
      query[o].emplace_back(l, r, i);
    }
  }
  TREE::getans();
  for (int i = 1; i <= q; ++i) {
    cout << -ans[i].sec << ' ' << ans[i].fir << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}