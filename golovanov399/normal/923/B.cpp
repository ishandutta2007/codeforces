#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

void solve(bool __attribute__((unused)) read) {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    vector<int> t(n);
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    
    multiset<li> cur;
    li sub = 0;
    
    for (int i = 0; i < n; ++i) {
        cur.insert(v[i] + sub);
        sub += t[i];
        
        li total = cur.size() * (li)t[i];
        while (!cur.empty() && *cur.begin() - sub <= 0) {
            total -= sub - *cur.begin();
            cur.erase(cur.begin());
        }
        
        cout << total << " ";
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    return 0;
}