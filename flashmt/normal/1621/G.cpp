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

using num = modnum<int(1e9) + 7>;

template<typename T>
struct FenwickTree
{
  int n, indexBase;
  vector<T> a;

  FenwickTree(int n, int indexBase = 1): n(n), indexBase(indexBase)
  {
    a = vector<T>(n + 1, 0);
  }

  void add(int x, T v)
  {
    for (int i = x + 1 - indexBase; i <= n; i += i & -i)
      a[i] += v;
  }

  T get(int x)
  {
    T res = 0;
    for (int i = x + 1 - indexBase; i; i -= i & -i)
      res += a[i];
    return res;
  }
};

void compress(vector<int> &a)
{
  vector<pair<int, int>> values;
  for (int i = 0; i < size(a); i++)
    values.push_back({a[i], -i});
  sort(begin(values), end(values));
  for (int i = 0; i < size(a); i++)
    a[i] = lower_bound(begin(values), end(values), make_pair(a[i], -i)) - begin(values);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    compress(a);
    vector<num> fLeft(n);
    FenwickTree<num> treeLeft(n, 0);
    for (int i = 0; i < n; i++)
    {
      fLeft[i] = treeLeft.get(a[i] - 1) + 1;
      treeLeft.add(a[i], fLeft[i]);
    }

    vector<num> fRight(n);
    FenwickTree<num> treeRight(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
      fRight[i] = treeRight.get(n - 1) - treeRight.get(a[i]) + 1;
      treeRight.add(a[i], fRight[i]);
    }

    vector<int> id(n);
    for (int i = 0; i < n; i++)
      id[a[i]] = i;

    vector<num> fBad(n);
    FenwickTree<num> treeBad(n, 0);
    for (int i = n - 1, bound = -1; i >= 0; i--)
      if (a[i] > bound)
      {
        for (int x = a[i]; x > bound; x--)
        {
          fBad[id[x]] = treeBad.get(n - 1) - treeBad.get(id[x]);
          if (x == a[i])
            fBad[id[x]]++;
          treeBad.add(id[x], fBad[id[x]]);
        }

        for (int x = a[i]; x > bound; x--)
          treeBad.add(id[x], -fBad[id[x]]);

        bound = a[i];
      }

    num ans;
    for (int i = 0; i < n; i++)
      ans += fLeft[i] * (fRight[i] - fBad[i]);
    cout << ans << endl;
  }
}