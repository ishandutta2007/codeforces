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

ll n, m, k;

void solve() {
    vector<pll> a, b;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        ll x, cnt = 1;
        cin >> x;
        
        while(x % m == 0) x /= m, cnt *= m; 
        
        if(a.size() && a.back().fi == x) a.back().se += cnt;
        else a.eb(x, cnt);
    }
    cin >> k;
    for(int i=1; i<=k; i++) {
        ll x, cnt = 1;
        cin >> x;
        
        while(x % m == 0) x /= m, cnt *= m; 
        
        if(b.size() && b.back().fi == x) b.back().se += cnt;
        else b.eb(x, cnt);
    }

    if(a.size() != b.size()) {
        cout << "No\n";
        return;
    }

    for(int i=0; i<a.size(); i++) {
        if(a[i] != b[i]) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}