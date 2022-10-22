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
int a[555][555];

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll ans = 0;
        for(int i=1; i<=2*n; i++) {
            for(int j=1; j<=2*n; j++) {
                cin >> a[i][j];
                if(i <= n && j <= n) ans += a[i][j];
                if(i > n && j > n) ans += a[i][j];
            }
        }

        cout << ans + min({a[1][n+1], a[1][2*n], a[n][n+1], a[n][2*n], a[n+1][1], a[n+1][n], a[2*n][1], a[2*n][n]}) << "\n";
    }
}