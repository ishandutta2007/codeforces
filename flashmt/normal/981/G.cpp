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

template<typename T>
struct SegmentTree
{
  const T DEFAULT = 0;
  int low, mid, high;
  T value, saveAdd, saveMul;
  SegmentTree *l, *r;

  T merge(T u, T v)
  {
    return u + v;
  }

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    value = saveAdd = 0;
    saveMul = 1;
    if (low == high)
      return;
    l = new SegmentTree(low, mid);
    r = new SegmentTree(mid + 1, high);
  }

  void pushDown()
  {
    if (int(saveAdd) == 0 && int(saveMul) == 1)
      return;
    l->value = l->value * saveMul + saveAdd * (mid - low + 1);
    l->saveMul *= saveMul;
    l->saveAdd = l->saveAdd * saveMul + saveAdd;
    r->value = r->value * saveMul + saveAdd * (high - mid);
    r->saveMul *= saveMul;
    r->saveAdd = r->saveAdd * saveMul + saveAdd;
    saveMul = 1;
    saveAdd = 0;
  }

  void mul(int x, int y)
  {
    if (low == x && high == y)
    {
      value *= 2;
      saveMul *= 2;
      saveAdd *= 2;
      return;
    }
    pushDown();
    if (x <= mid)
      l->mul(x, min(y, mid));
    if (mid < y)
      r->mul(max(x, mid + 1), y);
    value = merge(l->value, r->value);
  }

  void add(int x, int y)
  {
    if (low == x && high == y)
    {
      value += high - low + 1;
      saveAdd++;
      return;
    }
    pushDown();
    if (x <= mid)
      l->add(x, min(y, mid));
    if (mid < y)
      r->add(max(x, mid + 1), y);
    value = merge(l->value, r->value);
  }

  T get(int x, int y)
  {
    if (low == x && high == y)
      return value;
    pushDown();
    T t = x <= mid ? l->get(x, min(y, mid)) : DEFAULT;
    T u = mid < y ? r->get(max(x, mid + 1), y) : DEFAULT;
    return merge(t, u);
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const int N = 200000;
  int n, q;
  cin >> n >> q;
  SegmentTree<num> tree(0, n - 1);
  set<pair<int, int>> segs[N];
  for (int i = 0; i < n; i++)
    segs[i] = {{-1, -1}, {n, n}};

  while (q--)
  {
    int op, l, r, v;
    cin >> op >> l >> r;
    l--;
    r--;
    if (op == 1)
    {
      cin >> v;
      v--;
      auto low = segs[v].lower_bound({l, 0});
      low--;
      if (low->second < l)
        low++;
      auto high = segs[v].lower_bound({r + 1, 0});

      vector<pair<int, int>> toErase;
      int newL = l, newR = r;
      while (*low < *high)
      {
        if (l < low->first) tree.add(l, low->first - 1);
        else newL = min(newL, low->first);
        tree.mul(max(l, low->first), min(r, low->second));
        newR = max(newR, low->second);
        l = low->second + 1;
        toErase.push_back(*low++);
      }
      if (l <= r)
        tree.add(l, r);

      for (auto u : toErase)
        segs[v].erase(u);
      segs[v].insert({newL, newR});
    }
    else
    {
      num ans = tree.get(l, r);
      cout << ans << '\n';
    }
  }
}