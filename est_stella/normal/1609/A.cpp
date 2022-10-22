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
int a[20];
int cnt;

void solve() {
    cnt = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        while(a[i] % 2 == 0) {
            a[i] >>= 1;
            cnt++;
        }
    }

    sort(a, a+n);

    ll ans = 0;
    for(int i=0; i<n-1; i++) {
        ans += a[i];
    }
    ans += (ll) a[n-1] << cnt;

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