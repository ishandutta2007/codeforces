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
const int sz = 320;

int n, q;
ll a[100010];
ll b[100010];

ll mx[400010];
ll mn[400010];

void init(int node, int s, int e) {
    if(s == e) {
        mx[node] = mn[node] = b[s] - a[s];
        return;
    }

    int m = s + e >> 1;
    init(node*2, s, m);
    init(node*2+1, m+1, e);

    mx[node] = max(mx[node*2], mx[node*2+1]);
    mn[node] = min(mn[node*2], mn[node*2+1]);
}

ll Mx(int node, int s, int e, int l, int r) {
    if(r < s || e < l) return -INF;
    if(l <= s && e <= r) return mx[node];

    int m = s + e >> 1;
    return max(Mx(node*2, s, m, l, r), Mx(node*2+1, m+1, e, l, r));
}

ll Mn(int node, int s, int e, int l, int r) {
    if(r < s || e < l) return INF;
    if(l <= s && e <= r) return mn[node];

    int m = s + e >> 1;
    return min(Mn(node*2, s, m, l, r), Mn(node*2+1, m+1, e, l, r));
}

int main() {
    fast;

    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i], a[i] += a[i-1];
    for(int i=1; i<=n; i++) cin >> b[i], b[i] += b[i-1];

    init(1, 0, n);

    while(q--) {
        int L, R;
        cin >> L >> R;

        if(Mn(1, 0, n, L-1, R) < Mn(1, 0, n, L-1, L-1) || Mn(1, 0, n, L-1, L-1) != Mn(1, 0, n, R, R)) cout << -1 << "\n";
        else cout << Mx(1, 0, n, L-1, R) - Mn(1, 0, n, L-1, L-1) << "\n";
    }
}