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
int a[200010];

void solve() {
    cin >> n;

    for(int i=1; i<=n; i++) cin >> a[i];

    int ans = n-1;
    int l, r;
    for(int i=2; i<=n; i++) {
        l = i;
        if(a[i-1] == a[i]) break;
    }

    for(int i=n; i>1; i--) {
        r = i;
        if(a[i] == a[i-1]) break;
    }

    if(r-l <= 1) cout << max(0, r-l) << "\n";
    else cout << r-l-1 << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) solve();
}