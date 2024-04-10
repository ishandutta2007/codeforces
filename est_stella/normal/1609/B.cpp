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

int n, q;
string s;

int chk(int x) {
    if(x < 0 || x+2 >= n) return 0;
    return s[x] == 'a' && s[x+1] == 'b' && s[x+2] == 'c';
}

int main() {
    fast;

    cin >> n >> q;
    cin >> s;

    int ans = 0;
    for(int i=0; i<n; i++) ans += chk(i);

    for(int i=0; i<q; i++) {
        int x;
        string c;
        cin >> x >> c;
        x--;

        ans -= chk(x-2) + chk(x-1) + chk(x);
        s[x] = c[0];
        ans += chk(x-2) + chk(x-1) + chk(x);
        cout << ans << "\n";
    }
}