#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

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

#define MOD 998244353

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, k; fin >> n >> k;
    vector<ll> p(n); for (auto& x : p) fin >> x;
    ll out = n*(n+1)/2 - (n-k)*(n-k+1)/2;
    cout << out << " ";
    ll r = -1, count = 1;
    for (ll i = 0; i < n; i++) {
        if (p[i] > n-k) {
            if (r != -1) count = (count*(i-r))%MOD;
            r = i;
        }
    }
    cout << count << "\n";
}