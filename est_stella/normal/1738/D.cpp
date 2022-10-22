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
int a[100010];
int b[100010];
int cnt[100010];
int d[100010];

void dfs(int x) {
    if(x == 0 || x == n+1 || d[x]) return;
    dfs(b[x]);
    d[x] = d[b[x]] + 1;
}

void solve() {
    cin >> n;
    for(int i=0; i<=n+1; i++) d[i] = cnt[i] = 0;
    vector<int> v;
    int k = 0;
    for(int i=1; i<=n; i++) {
        cin >> b[i];
        cnt[b[i]]++;
        k = max(k, min(i, b[i]));
        v.eb(i);
    }
    for(int i=1; i<=n; i++) dfs(i);
    sort(all(v), [](int i, int j) {
        return mp(d[i], cnt[i]) < mp(d[j], cnt[j]);
    });
    cout << k << "\n";
    for(auto i : v) cout << i << " ";
    cout << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}