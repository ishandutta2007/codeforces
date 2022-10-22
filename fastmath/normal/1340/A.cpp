#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
int get(int i, set <int> &nu) {
    auto t = nu.find(i);
    --t;
    return i - *t;
}   
void solve() {
    int n;
    cin >> n;
    set <int> nu;
    for (int i = 0; i <= n + 1; ++i)
        nu.insert(i);
    vector <int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }                
    set <ii> ms;
    for (int i = 1; i <= n; ++i)
        ms.insert(mp(1, i));
    for (int x = 1; x <= n; ++x) {
        int i = pos[x];

        auto t = nu.find(i);
        auto l = prev(t);
        auto r = next(t);

        if (get(i, nu) != ms.rbegin()->f) {
            /*
            cout << x << ' ' << i << endl;
            cout << get(i, nu) << ' ' << ms.rbegin()->f << endl;
            */
            cout << "No" << endl;
            return;
        }   
        
        ms.erase(mp(get(i, nu), i));
        if (*r != n + 1) {
            ms.erase(mp(get(*r, nu), *r));
        }
        nu.erase(i);
        if (*r != n + 1) {
            ms.insert(mp(get(*r, nu), *r));        
        }
    }   
    cout << "Yes" << endl;    
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--)
        solve();
}