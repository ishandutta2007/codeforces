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
const int inf = 1e9;
const ll INF = 1e18;

int n;
int a[100010];
int b[100010];
int p[100010];
int sz[100010];

int Find(int x) {
    return p[x] ? p[x] = Find(p[x]) : x;
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    p[y] = x;
    sz[x] += sz[y];
}

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) p[i] = 0, sz[i] = 1;
    
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        cin >> b[i];
        Union(a[i], b[i]);
    }

    int cnt = 0;
    ll ans = 0;
    for(int i=1; i<=n; i++) if(p[i] == 0 && sz[i] % 2 == 1) cnt++;
    for(int i=1; i<=n; i++) {
        if(abs(n+1-2*i) <= cnt);
        else if(i <= n/2) ans -= 2*i;
        else ans += 2*i;
    }

    cout << ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}