#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define pre(x) cout<<fixed; cout.precision(x);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n;
int a[100010];

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    ll ans = 0;
    vector<int> v[2];
    for(int i=1; i<=n; i++) {
        int b;
        cin >> b;
        v[a[i]].eb(b);
        ans += b;
    }

    sort(all(v[0]));
    sort(all(v[1]));
    reverse(all(v[0]));
    reverse(all(v[1]));

    for(int i=0; i < v[0].size() && i < v[1].size(); i++) {
        ans += v[0][i] + v[1][i];
        if(i == v[0].size()-1 && i == v[1].size()-1) ans -= min(v[0][i], v[1][i]);
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