#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define em emplace
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair

typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const ll INF = 1e18;
const int inf = 1e9;

int n, m;
int a[100010];
int cnt[100010];
vector<int> g[100010];

int tree[100010];

void update(int i, int x) {
    for(; i<=100000; i+=i&-i) tree[i] += x;
}

int sum(int i) {
    int ret = 0;
    for(; i; i-=i&-i) ret += tree[i];
    return ret;
}

void solve() {
    cin >> n >> m;

    vector<int> v;
    for(int i=1; i<=n*m; i++) {
        g[i].clear();
        cin >> a[i];
        v.eb(a[i]);
    }

    sort(all(v));
    v.erase(unique(all(v)), v.end());

    for(int i=1; i<=n*m; i++) {
        a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
        cnt[a[i]]++;
        g[a[i]].eb(i);
    }

    vector<int> x;
    int cnt = 0;
    ll ans = 0;
    for(int i=1; i<=n*m; i++) {
        for(auto j : g[i]) {
            x.eb(j);
            cnt++;

            if(cnt == m) {
                sort(all(x));

                for(auto k : x) {
                    update(a[k], 1);
                    ans += sum(a[k]-1);
                }

                for(auto k : x) {
                    update(a[k], -1);
                }

                x.clear();
                cnt = 0;
            }
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