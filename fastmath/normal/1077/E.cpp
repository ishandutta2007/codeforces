#include <bits/stdc++.h>

using namespace std;

const int LG = 21;

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector <int> a(n);
    map <int, int> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        d[a[i]]++;
    }   
    vector <int> c;
    for (auto e : d) c.push_back(e.second);

    sort(c.begin(), c.end());
    vector <int> nc;
    for (int i = (int)c.size() - LG; i < (int)c.size(); ++i) {
        if (i < 0) continue;
        nc.push_back(c[i]);
    }

    int ans = 0;
    for (int i = 0; i + LG < (int)c.size(); ++i) {
        for (int t = 1; t <= c[i]; ++t) {
            int u = 0;
            int newans = t;
            int w = t << 1;
            while (1) {
                while (u < (int)nc.size() && nc[u] < w) ++u;
                if (u == (int)nc.size()) break;
                newans += w;
                w <<= 1;
                ++u;
            }
            ans = max(ans, newans);
        }   
    }   

    for (int i = 0; i < (int)nc.size(); ++i) {
        for (int t = 1; t <= nc[i]; ++t) {
            int u = i + 1;
            int newans = t;
            int w = t << 1;
            while (1) {
                while (u < (int)nc.size() && nc[u] < w) ++u;
                if (u == (int)nc.size()) break;
                newans += w;
                w <<= 1;
                ++u;
            }
            ans = max(ans, newans);            
        }   
    }   
    
    cout << ans << '\n';

    return 0;
}