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
const ll Mod = 998244353;

void solve() {
    string s;
    cin >> s;

    if(s.back() != 'B' || s.front() == 'B') {
        cout << "NO\n";
        return;
    }

    int cnt = 0;
    for(auto i : s) {
        if(i == 'A') cnt++;
        else cnt--;

        if(cnt < 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) solve();
}