#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

#define fir first
#define sec second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

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

const int N = 200010, Q = 500010, A = 26;

namespace TRIE {

int top, root;

int ch[N][A];
int fail[N], dfn[N], dfnr[N];
vector<int> fch[N];

void init() {
  root = ++top;
}

int ins(int o, int c) {
  if (!ch[o][c])
    ch[o][c] = ++top;
  return ch[o][c];
}

void build() {
  queue<int> q;
  for (int i = 0; i < A; ++i)
    if (ch[root][i]) {
      fail[ch[root][i]] = root;
      q.push(ch[root][i]);
    } else
      ch[root][i] = root;
  while (!q.empty()) {
    int o = q.front();
    q.pop();
    for (int i = 0; i < A; ++i)
      if (ch[o][i]) {
        fail[ch[o][i]] = ch[fail[o]][i];
        q.push(ch[o][i]);
      } else
        ch[o][i] = ch[fail[o]][i];
  }
}

void dfs(int u) {
  static int t;
  dfn[u] = ++t;
  for (int v : fch[u])
    dfs(v);
  dfnr[u] = t;
}

void failDFN() {
  for (int i = 2; i <= top; ++i)
    fch[fail[i]].push_back(i);
  dfs(root);
}

}

int n, q, sz;
int ans[Q];
int id[N];
string s[N];
vector<pair<int, int>> query[N];

int fw[N];

void ch(int k) {
  for (; k <= sz; k += k & -k)
    ++fw[k];
}

int qry(int k) {
  int ret = 0;
  for (; k; k &= k - 1)
    ret += fw[k];
  return ret;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  TRIE::init();

  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    int o = TRIE::root;
    for (char c : s[i])
      o = TRIE::ins(o, c - 'a');
    id[i] = o;
  }
  for (int i = 1; i <= q; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    query[r].emplace_back(k, i);
    query[l - 1].emplace_back(k, -i);
  }
  TRIE::build();
  TRIE::failDFN();
  sz = TRIE::top;
  for (int i = 1; i <= n; ++i) {
    int o = TRIE::root;
    for (char c : s[i]) {
      o = TRIE::ch[o][c - 'a'];
      ch(TRIE::dfn[o]);
    }
    for (const auto &pr : query[i]) {
      int res = qry(TRIE::dfnr[id[pr.fir]]) - qry(TRIE::dfn[id[pr.fir]] - 1);
      if (pr.sec > 0)
        ans[pr.sec] += res;
      else ans[-pr.sec] -= res;
    }
  }
  for (int i = 1; i <= q; ++i)
    cout << ans[i] << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}