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

void solve() {
    int a, b;
    cin >> a >> b;

    if(a < b) swap(a, b);

    int n = a + b;

    vector<int> ans;
    for(int i=0; i<=b; i++) {
        ans.eb(n/2-i + b-i);
        ans.eb(n-n/2-i + b-i);
    }

    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());

    cout << ans.size() << "\n";
    for(auto i : ans) cout << i << " ";
    cout << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}