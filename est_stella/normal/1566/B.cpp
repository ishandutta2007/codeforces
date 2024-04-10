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

void solve() {
    string s;
    cin >> s;

    int cnt = 0, mn = inf, mx = -inf;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '0') {
            cnt++;
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }

    if(!cnt) cout << "0\n";
    else if(mx - mn == cnt-1) cout << "1\n";
    else cout << "2\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}