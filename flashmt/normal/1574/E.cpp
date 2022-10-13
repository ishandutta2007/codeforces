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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n, k;
  cin >> m >> n >> k;
  vector<num> p2(max(m, n) + 1);
  for (int i = 0; i <= max(m, n); i++)
    p2[i] = i ? p2[i - 1] * 2 : 1;

  map<pair<int, int>, int> cells;
  vector<int> rowTypeCnt(4), colTypeCnt(4);
  rowTypeCnt[0] = m;
  colTypeCnt[0] = n;
  vector<vector<int>> rowCnt(m, vector<int>(2));
  vector<vector<int>> colCnt(n, vector<int>(2));

  auto getRowType = [&](int x)
  {
    int res = 0;
    for (int i = 0; i < 2; i++)
      if (rowCnt[x][i])
        res |= 1 << i;
    return res;
  };

  auto getColType = [&](int x)
  {
    int res = 0;
    for (int i = 0; i < 2; i++)
      if (colCnt[x][i])
        res |= 1 << i;
    return res;
  };

  auto remove = [&](int x, int y)
  {
    if (!cells.count({x, y}))
      return;
    rowTypeCnt[getRowType(x)]--;
    colTypeCnt[getColType(y)]--;
    int v = cells[{x, y}];
    cells.erase({x, y});
    rowCnt[x][(x + y + v) & 1]--;
    colCnt[y][(x + y + v) & 1]--;
    rowTypeCnt[getRowType(x)]++;
    colTypeCnt[getColType(y)]++;
  };

  auto add = [&](int x, int y, int v)
  {
    rowTypeCnt[getRowType(x)]--;
    colTypeCnt[getColType(y)]--;
    rowCnt[x][(x + y + v) & 1]++;
    colCnt[y][(x + y + v) & 1]++;
    cells[{x, y}] = v;
    rowTypeCnt[getRowType(x)]++;
    colTypeCnt[getColType(y)]++;
  };

  while (k--)
  {
    int x, y, op;
    cin >> x >> y >> op;
    remove(--x, --y);
    if (op >= 0)
      add(x, y, op);

    if (rowTypeCnt[3] && colTypeCnt[3]) cout << 0 << '\n';
    else if (rowTypeCnt[3]) cout << p2[colTypeCnt[0]] << '\n';
    else if (colTypeCnt[3]) cout << p2[rowTypeCnt[0]] << '\n';
    else if (rowTypeCnt[0] == m) cout << p2[m] + p2[n] - 2 << '\n';
    else cout << p2[rowTypeCnt[0]] + p2[colTypeCnt[0]] - (rowTypeCnt[1] == 0 || rowTypeCnt[2] == 0) << '\n';
  }
}