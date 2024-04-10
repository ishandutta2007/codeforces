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

int n;
int in[200010];
vector<int> g[200010];
set<int> S;

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) g[i].clear();

    for(int i=1; i<=n; i++) {
        cin >> in[i];

        for(int j=0; j<in[i]; j++) {
            int x;
            cin >> x;
            g[x].eb(i);
        }

        if(!in[i]) S.insert(i);
    }

    int x = n+1, ans = 0, cnt = 0;;
    while(S.size()) {
        if(S.lower_bound(x) == S.end()) x = 0, ans++;
        x = *S.lower_bound(x);
        cnt++;
        S.erase(x);

        for(auto i : g[x]) {
            in[i]--;
            if(!in[i]) S.insert(i);
        }
    }

    if(cnt < n) cout << "-1\n";
    else cout << ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}