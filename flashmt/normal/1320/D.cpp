#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
const int P = 67;

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

num p[N];

struct Node
{
  int cnt, first, last;
  num h;

  bool operator ==(const Node &u)
  {
    return cnt == u.cnt && h == u.h;
  }
};

const Node DEFAULT = {0, 0, 0, 0};

struct SegmentTree
{
  int low, mid, high;
  Node v;
  SegmentTree *l, *r;

  Node merge(Node u, Node v)
  {
    if (!u.cnt)
      return v;
    if (!v.cnt)
      return u;
    if (u.last && v.first)
    {
      num h = u.h - p[u.cnt - 1] + (v.h - 1) / p[1] * p[u.cnt - 1];
      int first = u.cnt == 1 ? 0 : u.first;
      int last = v.cnt == 1 ? 0 : v.last;
      return {u.cnt + v.cnt - 2, first, last, h};
    }
    return {u.cnt + v.cnt, u.first, v.last, u.h + v.h * p[u.cnt]};
  }

  SegmentTree(int low, int high, string &s): low(low), high(high)
  {
    mid = (low + high) / 2;
    if (low == high)
    {
      int x = s[low] - '0';
      v = {1, x, x, x};
    }
    else
    {
      l = new SegmentTree(low, mid, s);
      r = new SegmentTree(mid + 1, high, s);
      v = merge(l->v, r->v);
    }
  }

  Node get(int x, int y)
  {
    if (low == x && high == y)
      return v;
    Node t = x <= mid ? l->get(x, min(y, mid)) : DEFAULT;
    Node u = mid < y ? r->get(max(x, mid + 1), y) : DEFAULT;
    return merge(t, u);
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;

  p[0] = 1;
  for (int i = 1; i <= n; i++)
    p[i] = p[i - 1] * P;

  SegmentTree tree(0, n - 1, s);

  int q;
  cin >> q;
  while (q--)
  {
    int x, y, len;
    cin >> x >> y >> len;
    x--;
    y--;
    Node u = tree.get(x, x + len - 1);
    Node v = tree.get(y, y + len - 1);
    cout << (u == v ? "Yes" : "No") << '\n';
  }
}