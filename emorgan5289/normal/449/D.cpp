#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 1<<20;
const ll mod = 1000000007;
ll p[maxn], dp[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        ll a; cin >> a;
        dp[a]++;
    }
    for (ll i = 0; i < 20; i++)
        for (ll j = 0; j < maxn; j++)
            if ((~j)&(1<<i))
                dp[j] += dp[j^(1<<i)];
    p[0] = 1;
    for (ll i = 1; i < maxn; i++)
        p[i] = (p[i-1]<<1)%mod;
    ll out = 0;
    for (ll i = 0; i < maxn; i++) {
        if (__builtin_popcount(i)&1)
            out = (out+mod-p[dp[i]])%mod;
        else
            out = (out+p[dp[i]])%mod;
    }
    cout << out << "\n";
}