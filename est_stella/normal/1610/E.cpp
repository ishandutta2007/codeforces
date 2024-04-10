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

void solve() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);

    int ans = 0;
    for(int i=0; i<n; i++) {
        int x = 0, y = upper_bound(a, a+n, a[i]) - lower_bound(a, a+n, a[i]);
        for(int j = upper_bound(a+i+1, a+n, a[i] + x) - a; j < n; j = lower_bound(a+j+1, a+n, a[j] + x) - a, y++) {
            x = a[j] - a[i];
        }
        ans = max(ans, y);
    }
    cout << n - ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}