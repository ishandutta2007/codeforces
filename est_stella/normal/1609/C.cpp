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

int n, e;
int a[200010];
int sp[1000010];
vector<int> p;

void solve() {
    cin >> n >> e;
    for(int i=1; i<=n; i++) cin >> a[i];

    ll ans = 0;
    for(int i=1; i<=e; i++) {
        int cnt[2] = {-1, 0};
        for(int j=i; j<=n; j+= e) {
            if(a[j] == 1) {
                ans += cnt[0]+1;
                cnt[1]++;
            }
            else if(!sp[a[j]]) {
                cnt[0] = cnt[1];
                cnt[1] = 0;
                ans += cnt[0];
            }
            else {
                cnt[1] = 0;
                cnt[0] = -1;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    fast;

    for(int i=2; i<=1000000; i++) {
        if(!sp[i]) {
            p.eb(i);
        }
        for(auto j : p) {
            if(i * j > 1000000) break;
            sp[i * j] = j;
            if(i % j == 0) break;
        }
    }

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}