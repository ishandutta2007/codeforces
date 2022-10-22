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

void solve() {
    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;

    int x = 0, y = 0;
    for(int i=0; i<n; i++) x += s[i] == '1';
    for(int i=0; i<n; i++) y += t[i] == '1';

    int ans = inf;
    if(x == y) {
        int dif = 0;
        for(int i=0; i<n; i++) dif += s[i] != t[i];
        ans = min(ans, dif);
    }
    if(x > 0 && n-x+1 == y) {
        int dif = 0;
        int flag = 0;
        for(int i=0; i<n; i++) {
            dif += s[i] == t[i];
            if(s[i] == t[i] && s[i] == '1') flag = 1;
        }

        ans = min(ans, dif - flag + 1);
    }

    if(ans < inf) cout << ans << "\n";
    else cout << "-1\n";
}

int main() {
    fast;

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}