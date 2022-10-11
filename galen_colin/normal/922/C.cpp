#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    ll n, k; cin >> n >> k;
    
    // if (k >= n) {
    //     cout << "No\n";
    //     return 0;
    // }
    
    ll stop = min(10000000LL, k);
    bool vis[stop + 3];
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= stop; i++) {
        ll v = n % i;
        if (vis[v]) {
            cout << "No\n";
            return 0;
        }
        vis[v] = 1;
    }
    cout << "Yes\n";
}