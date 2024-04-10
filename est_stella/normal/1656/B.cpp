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

int n, k;
int a[200010];

void solve() {
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);

    for(int i=0; i<n; i++) {
        if(upper_bound(a, a+n, a[i]+k) != lower_bound(a, a+n, a[i]+k)) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}