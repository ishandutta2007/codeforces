#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
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

template<int M> string to_string(modnum<M> x) {
  return to_string(int(x));
}

using num = modnum<998244353>;

const int C = 17;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;

  int total = count(begin(s), end(s), '?');

  vector<vector<short>> f(1 << C, vector<short>(n / 2 + 1));
  for (int i = 0; i < n; i++)
    for (int r : {i, i + 1})
    {
      int mask = 0, cnt = 0;
      for (int l = i; l >= 0 && r < n; l--, r++)
      {
        if (s[l] == s[r]) cnt += l < r && s[l] == '?';
        else if (s[l] == '?')
        {
          mask |= 1 << s[r] - 'a';
          cnt++;
        }
        else if (s[r] == '?')
        {
          mask |= 1 << s[l] - 'a';
          cnt++;
        }
        else break;
        f[mask][cnt]++;
      }
    }

  vector<num> ans(1 << C);
  for (int i = 0; i < C; i++)
    for (int mask = 0; mask < 1 << C; mask++)
      if (mask >> i & 1)
        for (int j = 0; j <= n / 2; j++)
          f[mask][j] += f[mask ^ 1 << i][j];

  vector<vector<num>> p(C + 1, vector<num>(n + 1));
  for (int i = 1; i <= C; i++)
    for (int j = 0; j <= n; j++)
      p[i][j] = j ? p[i][j - 1] * i : 1;

  int q;
  cin >> q;
  while (q--)
  {
    string t;
    cin >> t;
    int mask = 0;
    for (char c : t)
      mask |= 1 << c - 'a';

    num ans;
    for (int j = 0; j <= n / 2; j++)
      ans += p[size(t)][total - j] * f[mask][j];
    cout << ans << '\n';
  }
}