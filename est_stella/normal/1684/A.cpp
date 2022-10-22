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
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if(n == 2) {
        cout << s[1] << "\n";
        return;
    }

    int mn = 10;
    for(int i=0; i<n; i++) {
        mn = min(mn, s[i] - '0');
    }
    cout << mn << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}