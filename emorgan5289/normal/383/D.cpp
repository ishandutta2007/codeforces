#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 12005, maxa = 30005;
const ll mod = 1000000007;
ll dp[maxa], temp[maxa];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    dp[maxn] = 1;
    ll out = 0;
    for (int i = 0; i < n; i++) {
        copy(dp, dp+maxa, temp);
        ll a; cin >> a;
        for (int j = a; j < maxa-a; j++)
            dp[j] = (temp[j-a]+temp[j+a])%mod;
        dp[maxn] = (dp[maxn]+1)%mod;
        out = (out+dp[maxn])%mod;
    }
    cout << out-n << "\n";
}