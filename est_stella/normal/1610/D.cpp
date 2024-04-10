#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplaces
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = inf + 7;

int n;
int a[200010];
int b[111];
int e[200010];

int main() {
    fast;

    cin >> n;
    e[0] = 1;
    for(int i=1; i<=n; i++) e[i] = e[i-1] * 2 % Mod;

    for(int i=1; i<=n; i++) {
        cin >> a[i];
        int cnt = 0;
        while(a[i] % 2 == 0) a[i] >>= 1, cnt++;
        b[cnt]++;
    }

    ll ans = (e[b[0]] + Mod - 1) * e[n-b[0]] % Mod;
    n -= b[0];
    for(int i=1; i<100; i++) {
        if(b[i] == 0) continue;
        ll x = e[b[i]-1] + Mod - 1;
        x = x * e[n-b[i]] % Mod;
        ans += x;
        ans %= Mod;
        n -= b[i];
    }

    cout << ans;
}