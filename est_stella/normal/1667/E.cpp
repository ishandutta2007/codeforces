#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n;
ll f[200010];
ll in[200010];
ll ans[200010];

ll inv(ll a) {
    ll b = Mod - 2, ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return ret;
}

int main() {
    fast;

    cin >> n;

    f[0] = 1;
    for(int i=1; i<=n; i++) {  
        f[i] = f[i-1] * i % Mod;
    }

    in[n] = inv(f[n]);
    for(int i=n; i>=1; i--) {
        in[i-1] = in[i] * i % Mod;
    }

    for(int i=2; i<=n/2+1; i++) {
        ans[i] = f[n/2] * in[i-1] % Mod * in[n/2-i+1] % Mod * f[i-2] % Mod * f[n-i] % Mod;
    }

    ll sum = 0;
    for(int i=n; i>1; i--) {
        sum += Mod - ans[i];
        sum %= Mod;
        ans[i] = (i * ans[i] + sum) % Mod;
    }
    ans[1] = (f[n-1] + sum) % Mod;

    for(int i=1; i<=n; i++) cout << ans[i] << " ";
}