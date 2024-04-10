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
const ll inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n;
int a[200010];
vector<int> g[200010];

void solve() {
    cin >> n;

    set<int> S;
    for(int i=1; i<=n; i++) cin >> a[i], g[a[i]].eb(i), S.insert(a[i]);

    while(S.size()) {
        vector<int> v, er;
        for(auto i : S) {
            v.eb(g[i].back());
            g[i].pop_back();
            if(g[i].size() == 0) er.eb(i);
        }

        for(auto i: er) S.erase(i);

        for(int i=1; i<v.size(); i++) {
            swap(a[v[i-1]], a[v[i]]);
        }
    }

    for(int i=1; i<=n; i++) cout << a[i] << " ";
    cout << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) solve();
}