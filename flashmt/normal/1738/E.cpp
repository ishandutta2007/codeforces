#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
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

template<typename T> T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

template<int M> string to_string(modnum<M> x) {
  return to_string(int(x));
}

using num = modnum<998244353>;

vector<num> fact, invFact;

void initFact(int n)
{
  fact.resize(n + 2);
  invFact.resize(n + 2);
  fact[0] = 1;
  for (int i = 1; i <= n + 1; i++)
    fact[i] = fact[i - 1] * i;
  invFact[n + 1] = inv(fact[n + 1]);
  for (int i = n; i >= 0; i--)
    invFact[i] = invFact[i + 1] * (i + 1);
}

num c(int n, int k)
{
  return 0 <= k && k <= n ? fact[n] * invFact[k] * invFact[n - k] : 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  initFact(1e5);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;
    vector<long long> pre(n + 1), suf(n + 2);
    map<long long, int> cntPre, cntSuf, maxPreId;
    for (int i = 0; i < n; i++)
    {
      pre[i + 1] = pre[i] + a[i];
      cntPre[pre[i + 1]]++;
      maxPreId[pre[i + 1]] = i + 1;
    }

    long long overlap = -1;
    for (int i = n; i; i--)
    {
      suf[i] = suf[i + 1] + a[i - 1];
      if (suf[i] == pre[i])
      {
        assert(overlap < 0 || overlap == suf[i]);
        overlap = suf[i];
      }
      if (maxPreId.count(suf[i]) && maxPreId[suf[i]] < i)
        cntSuf[suf[i]]++;
    }
    cntPre.erase(overlap);

    num ans = 1;
    for (auto [x, u] : cntPre)
      if (cntSuf.count(x))
      {
        int v = cntSuf[x];
        num ways;
        for (int i = 0; i <= min(u, v); i++)
          ways += c(u, i) * c(v, i);
        ans *= ways;
      }

    // handle overlapping value
    if (overlap >= 0)
    {
      int l = 0, r = 0;
      for (int i = 1; i <= n; i++)
        if (pre[i] == overlap)
        {
          if (!l)
            l = i;
          r = i;
        }

      int ll = n + 1, rr = n + 1;
      for (int i = n; i; i--)
        if (suf[i] == overlap)
        {
          if (rr > n)
            rr = i;
          ll = i;
        }

      r = min(r, rr);
      ll = max(ll, l);
      // 0 <= preLen, sufLen <= 1
      int preLen = ll - l, shared = min(r, rr) - max(l, ll) + 1, sufLen = rr - r;
      num ways = 0;
      for (int i = 0; i <= preLen; i++)
        for (int j = 0; j <= sufLen; j++)
        {
          int diff = abs(i - j);
          for (int k = diff; k <= shared; k += 2)
            ways += c(shared, k);
        }

      ans *= ways;
    }

    cout << ans << endl;
  }
}