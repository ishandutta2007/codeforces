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
int ans[100010];

int query(int x) {
    cout << "? " << x << endl;
    cin >> x;
    if(x == 0) exit(0);
    return x;
}

void solve() {
    cin >> n;
    set<int> s;
    for(int i=1; i<=n; i++) s.insert(i);

    while(s.size()) {
        int pos = *s.begin();
        int st = query(pos), cur;
        cur = st;
        while(1) {
            int nxt = query(pos);
            s.erase(cur);
            ans[cur] = nxt;
            cur = nxt;
            if(cur == st) break;
        }
    }

    cout << "! ";
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}