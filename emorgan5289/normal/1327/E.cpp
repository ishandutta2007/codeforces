#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

#define mod 998244353ll

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n; fin >> n;
    for (ll i = 1; i < n-1; i++) {
        ll out = (10ll*2ll*9ll*modpow(10ll, n-i-1ll, mod))%mod;
        out += (81ll*10ll*modpow(10ll, n-i-2ll, mod)*(n-1ll-i))%mod;
        out %= mod;
        cout << out << "\n";
    }
    if (n > 1) cout << ((10ll*2ll*9ll)%mod) << "\n";
    cout << "10\n";
}