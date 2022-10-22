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

int n, k;
ll s[100010];
ll a[100010];

void solve() {
    cin >> n >> k;
    for(int i=n-k+1; i<=n; i++) cin >> s[i];
    if(k == 1) {
        cout << "Yes\n";
        return;
    }
    for(int i=n-k+2; i<=n; i++) {
        a[i] = s[i] - s[i-1];
        if(i > n-k+2 && a[i] < a[i-1]) {
            cout << "No\n";
            return;
        }
    }
    if(s[n-k+1] <= a[n-k+2] * (n-k+1)) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}