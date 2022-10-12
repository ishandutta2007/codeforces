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

const ll N = 2e6+5, mod = 1e9+7;
ll f[N][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    f[3][1] = 4;
    for (int i = 4; i < N; i++) {
        f[i][0] = (2*f[i-2][1]+f[i-1][1])%mod;
        f[i][1] = (2*f[i-2][0]+f[i-1][0]+4)%mod;
        if (i%3 == 2) f[i][1] = f[i][0];
    }
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << f[n][1] << "\n";
    }
}