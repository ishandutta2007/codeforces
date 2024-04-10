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

string s, t;

void solve() {
    cin >> t >> s;

    reverse(all(t));

    for(int i=0; i<t.size() && s.size(); i++) {
        if(t[i] != s.back()) i++;
        else {
            s.pop_back();
        }
    }

    if(s.empty()) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    fast;

    int t;
    cin >> t;

    while(t--) {
        solve();
    }   
}