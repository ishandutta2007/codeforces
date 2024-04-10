#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        int m = 0;
        while(n >= (1 << m)) m += 1;
        vector<set<LL>> v(1 << m);
        for (int i = 1, a; i <= n; i += 1) {
            cin >> a;
            v[a].insert(i);
            while(v[a].size() > 2) v[a].erase(v[a].begin());
        }
        for (int i = 0; i < m; i += 1)
            for (int j = 0; j < (1 << m); j += 1) {
                if ((j >> i) & 1) {
                    for (int k : v[j ^ (1 << i)]) v[j].insert(k);
                    while (v[j].size() > 2) v[j].erase(v[j].begin());
                }
            }
        LL ans = LLONG_MIN;
        for (int i = 0; i < (1 << m); i += 1) {
            if (v[i].size() == 2) {
                ans = max(ans, *v[i].begin() * *v[i].rbegin() - k * i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}