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
int a[11];
string ans;

void f(int x, int y, int z) {
    if(x == n) {
        if(y == 0 && z > 0) {
            ans = "YES";
        }
        return;
    }

    f(x+1, y + a[x], z+1);
    f(x+1, y, z);
    f(x+1, y - a[x], z+1);
}

void solve() {
    ans = "NO";

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    f(0, 0, 0);

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