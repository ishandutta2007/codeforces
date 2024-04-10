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
string s, t;

void solve() {
    cin >> n;
    cin >> s;
    t = s;

    sort(all(s));

    int ans = 0;    
    for(int i=0; i<n; i++) if(s[i] != t[i]) ans++;

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