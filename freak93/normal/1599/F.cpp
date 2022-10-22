#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ull modmul(ull a, ull b, ull mod) {
	ll ret = a * b - mod * ull(1.L / mod * a * b);
	return ret + mod * (ret < 0) - mod * (ret >= (ll)mod);
}

template<ll MOD>
struct ModInt {
  ll x;
  ModInt(ll x = 0) : x(x + (x < 0) * MOD - (x >= MOD) * MOD){}
  ModInt operator+(ModInt o) { return x + o.x; }
  ModInt operator-(ModInt o) { return x - o.x; }
  ModInt operator*(ModInt o) { return modmul(x, o.x, MOD); }
  ModInt operator/(ModInt b) { return *this * b.inv(); }
  ModInt inv() { return pow(MOD - 2); }
  ModInt pow(long long e) {
    if (!e) return 1;
    ModInt r = pow(e / 2); r = r * r;
    return e % 2 ? *this * r : r;
  }
  bool operator==(ModInt o) { return x == o.x; }
};


template<typename Hash>
struct Fenwick {
  vector<Hash> T;
  int n;
  Fenwick(int n) : T(n + 1), n(n) {}
  void Update(int pos, Hash val) {
    for (++pos; pos > 0; pos -= (pos & -pos)) 
      T[pos] = T[pos] + val;
  }
  Hash Query(int pos) {
    Hash ans = 0;
    for (++pos; pos <= n; pos += (pos & -pos))
      ans = ans + T[pos];
    return ans;
  }
};

using M1 = ModInt<1000000007LL>;
using M2 = ModInt<3728000026097LL>;
M2 B = 177240789854LL;


pair<M2, M2> Compute(M2 x, int k) {
  if (k == 1) return {1, x};
  if (k % 2 == 1) {
    auto [a, b] = Compute(x, k - 1);
    return make_pair(a * x + 1, b * x);
  } else {
    auto [a, b] = Compute(x, k / 2);
    return {a * (b + 1), b * b};
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) 
    cin >> v[i];
  
  vector<vector<tuple<int, int, int>>> qrs(n);
  for (int i = 0; i < q; ++i) {
    int l, r, d; cin >> l >> r >> d; --l; --r;
    qrs[r].emplace_back(l, d, i);
  }

  map<int, int> mp;
  Fenwick<int> F1(n);
  Fenwick<M1> F2(n);
  Fenwick<M2> F3(n);

  vector<int> ans(q);
  for (int i = 0; i < n; ++i) {
    int& last = mp[v[i]];
    M2 pw = B.pow(v[i]);
    // cerr << "pw=" << pw.x << endl;
    if (last) {
      F1.Update(last - 1, -1);
      F2.Update(last - 1, v[i]);
      F3.Update(last - 1, M2(0) - pw);
    }
    F1.Update(i, 1);
    F2.Update(i, v[i]);
    F3.Update(i, pw);
    last = i + 1;
    
    for (auto [l, d, j] : qrs[i]) {
      int k = F1.Query(l);
      M1 sum = F2.Query(l);
      // x * k + d * k * (k - 1) / 2 = sum
      M1 x = (sum - M1(k) * (k - 1) / 2 * d) / k;
      // cerr << "l=" << l << " r=" << i << " d=" << d << " sum=" << sum.x << " k=" << k << " x=" << x.x << endl;
      
      M2 sum2 = F3.Query(l);
      M2 chk = B.pow(x.x) * Compute(B.pow(d), k).first;
      // cerr << "sum2=" << sum2.x << " chk=" << chk.x << endl;
      if (sum2 == chk) {
        ans[j] = 1;
      } else {
        ans[j] = 0;
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    if (ans[i]) cout << "Yes\n";
    else cout << "No\n";
  }


  return 0;
}