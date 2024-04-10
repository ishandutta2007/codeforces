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
const ll Mod = 998244353;

int n;
int a[500010];
int mx[500010];
int mn[500010];

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    mx[1] = mn[1] = 1;
    for(int i=2; i<=n; i++) {
        if(a[mx[i-1]] < a[i]) mx[i] = i;
        else mx[i] = mx[i-1];

        if(a[mn[i-1]] > a[i]) mn[i] = i;
        else mn[i] = mn[i-1];
    }

    int ans = 0;
    for(int i = mx[n], j=0; i > 1; j++, ans++) {
        if(j & 1) i = mx[i];
        else i = mn[i];
    }

    for(int i=2; i<=n; i++) {
        if(a[n-mx[i-1]+1] < a[n-i+1]) mx[i] = i;
        else mx[i] = mx[i-1];

        if(a[n-mn[i-1]+1] > a[n-i+1]) mn[i] = i;
        else mn[i] = mn[i-1];
    }

    for(int i = mx[n], j=0; i > 1; j++, ans++) {
        if(j & 1) i = mx[i];
        else i = mn[i];
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