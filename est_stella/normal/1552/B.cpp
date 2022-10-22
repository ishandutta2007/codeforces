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
int a[50010][5];

bool comp(int i, int j) {
    int cnt = 0;
    for(int k=0; k<5; k++) {
        if(a[i][k] < a[j][k]) cnt++;
    }

    return cnt > 2;
}

void solve() {
    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<5; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 1;

    for(int i=2; i<=n; i++) {
        if(comp(i, ans)) ans = i;
    }

    for(int i=1; i<=n; i++) {
        if(ans == i) continue;
        if(comp(i, ans)) {
            cout << "-1\n";
            return;
        }
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