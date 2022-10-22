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

struct BIT {
    int n;
    int tree[1000010];

    void init(int N) {
        n = N;
        for(int i=1; i<=n; i++) tree[i] = -inf;
    }

    void update(int i, int x) {
        for(i; i <= n; i += i & -i) tree[i] = max(tree[i], x);
    }

    int cal(int i) {
        int ret = -inf;
        for(i; i; i -= i & -i) ret = max(ret, tree[i]);
        return ret;
    }
} T;

int n;
ll a[500010];
int dp[1000010];

void solve() {
    cin >> n;

    T.init(2*n);
    a[0] = 0;
    for(int i=0; i<=2*n; i++) dp[i] = -inf;

    vector<ll> comp;
    comp.eb(0);
    for(int i=1; i<=n; i++) cin >> a[i], a[i] += a[i-1], comp.eb(a[i]);

    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());

    a[0] = lower_bound(all(comp), 0) - comp.begin() + 1;
    dp[lower_bound(all(comp), 0) - comp.begin() + 1] = 0;
    T.update(lower_bound(all(comp), 0) - comp.begin() + 1, 0);

    for(int i=1; i<=n; i++) {
        a[i] = lower_bound(all(comp), a[i]) - comp.begin() + 1;
        
        dp[a[i]] = max(dp[a[i]], dp[a[i-1]]-1);
        dp[a[i]] = max(dp[a[i]], T.cal(a[i]-1) + i);
        T.update(a[i], dp[a[i]]-i);

        //cout << i << " " << a[i] << " " << dp[a[i]] << "\n";

        if(i == n) {
            cout << dp[a[i]] << "\n";
        }
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}