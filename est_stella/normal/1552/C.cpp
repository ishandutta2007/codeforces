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

int n, k;
int x[111], y[111];
bool chk[222];
vector<int> v;

bool cross(int i, int j) {
    if(x[i] < x[j] && x[j] < y[i] && y[i] < y[j]) return true;
    swap(i, j);
    if(x[i] < x[j] && x[j] < y[i] && y[i] < y[j]) return true;

    return false;
}

void solve() {
    cin >> n >> k;

    for(int i=1; i<=2*n; i++) chk[i] = false;

    for(int i=0; i<k; i++) {
        cin >> x[i] >> y[i];

        if(x[i] > y[i]) swap(x[i], y[i]);

        chk[x[i]] = chk[y[i]] = true;
    }

    v.clear();
    for(int i=1; i<=2*n; i++) {
        if(!chk[i]) v.eb(i);
    }

    for(int i=0; i<n-k; i++) {
        x[i+k] = v[i];
        y[i+k] = v[i+n-k];
    }

    for(int i=0; i<n; i++) {

    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(cross(i, j)) ans++;
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