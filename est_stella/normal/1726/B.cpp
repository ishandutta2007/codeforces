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
const ll Mod = 1e9+7;

int n, m;

void solve() {
    cin >> n >> m;

    if(m < n) {
        cout << "No\n";
        return;
    }
    if(m == n) {
        cout << "Yes\n";
        for(int i=1; i<=n; i++) cout << "1 ";
        cout << "\n";
        return;
    }
    if(n & 1) {
        cout << "Yes\n";
        for(int i=1; i<n; i++) cout << "1 ";
        cout << m-n+1 << "\n"; 
    }
    else if(m & 1) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
        for(int i=1; i<=n-2; i++) cout << "1 ";
        cout << (m-n+2)/2 << " " << (m-n+2)/2 << "\n";
    }
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}