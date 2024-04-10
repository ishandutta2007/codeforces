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

bool solve(int u, int v) {
    if(u > v) return false;
    if(u == v) return true;
    
    vector<int> a, b;
    for(int i=0; i<30; i++) {
        if((1 << i) & u) a.eb(i); 
    }
    for(int i=0; i<30; i++) {
        if((1 << i) & v) b.eb(i);
    }
    
    if(a.size() < b.size()) return false;

    while(a.back() == b.back()) a.pop_back(), b.pop_back();
    
    for(int i=0; i<b.size(); i++) {
        if(a[i] > b[i]) return false;
    }

    return true;
}

int main() {
    fast;

    int q;
    cin >> q;

    while(q--) {
        int u, v;
        cin >> u >> v;
        if(solve(u, v)) cout << "YES\n";
        else cout << "NO\n";
    }
}