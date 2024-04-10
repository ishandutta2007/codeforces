#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

void solve() {
    string s, t;
    cin >> s >> t;

    reverse(all(t));

    bool chk[26] = {};

    for(auto i : t) {
        while(s.size() && s.back() != i) {
            chk[s.back() - 'A'] = true;
            s.pop_back();
        }
        if(s.empty() || chk[i-'A']) {
            cout << "NO\n";
            return;
        }
        
        s.pop_back();
    }

    cout << "YES\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}