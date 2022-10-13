#include <bits/stdc++.h>
using namespace std;

template<int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

private:
  using ll = long long;

  int v;

  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

public:

  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
  friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD-v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }

  modnum operator- () const {
    return neg();
  }
  modnum operator+ () const {
    return modnum(*this);
  }

  modnum& operator ++ () {
    v ++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }
  modnum& operator += (const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator -= (const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator *= (const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator /= (const modnum& o) {
    return *this *= o.inv();
  }

  friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
  friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template<typename T> T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

template<int M> string to_string(modnum<M> x) {
  return to_string(int(x));
}

using num = modnum<998244353>;

struct TopoSort
{
  int n;
  vector<vector<int>> a;
  vector<int> degIn, order;

  TopoSort(int n): n(n)
  {
    a = vector<vector<int>>(n);
    degIn = vector<int>(n);
  }

  void addEdge(int x, int y)
  {
    a[x].push_back(y);
    degIn[y]++;
  }

  int sort()
  {
    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!degIn[i])
        q.push(i);
    while (!empty(q))
    {
      int x = q.front();
      q.pop();
      order.push_back(x);
      for (int y : a[x])
        if (!--degIn[y])
          q.push(y);
    }
    return size(order) == n;
  }
};

int gauss(vector<vector<num>> a, vector<num> b, vector<num> &x)
{
  int n = size(a), m = size(x), rank = 0;
  vector<int> col(m);
  iota(begin(col), end(col), 0);
  for (int i = 0; i < n; i++)
  {
    int pr, pc;
    num pv = 0;
    for (int j = i; j < n; j++)
      for (int k = i; k < m; k++)
        if (a[j][k] != 0)
        {
          pr = j;
          pc = k;
          pv = a[j][k];
        }

    if (pv == 0)
    {
      for (int j = i; j < n; j++)
        if (b[j] != 0)
          return -1;
      break;
    }

    swap(a[i], a[pr]);
    swap(b[i], b[pr]);
    swap(col[i], col[pc]);
    for (int j = 0; j < n; j++)
      swap(a[j][i], a[j][pc]);
    pv = 1 / a[i][i];
    for (int j = i + 1; j < n; j++)
    {
      num coef = a[j][i] * pv;
      b[j] -= coef * b[i];
      for (int k = i + 1; k < m; k++)
        a[j][k] -= coef * a[i][k];
    }
    rank++;
  }

  x.assign(m, 0);
  for (int i = rank - 1; i >= 0; i--)
  {
    b[i] /= a[i][i];
    x[col[i]] = b[i];
    for (int j = 0; j < i; j++)
      b[j] -= a[j][i] * b[i];
  }
  return rank;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  TopoSort ts(n);
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    ts.addEdge(--x, --y);
  }
  ts.sort();
  vector<int> g(n), cnt(512);
  for (int i = n - 1; i >= 0; i--)
  {
    int x = ts.order[i];
    set<int> s;
    for (int y : ts.a[x])
      s.insert(g[y]);
    while (s.count(g[x]))
      g[x]++;
    cnt[g[x]]++;
  }

  vector<vector<num>> a(512, vector<num>(512));
  vector<num> b(512), x(512);
  for (int i = 0; i < 512; i++)
  {
    a[i][i] = 1;
    for (int j = 0; j < 512; j++)
      a[i][i ^ j] -= num(cnt[j]) / num(n + 1);
    if (i)
      b[i] = num(1) / num(n + 1);
  }
  gauss(a, b, x);
  cout << x[0] << endl;
}