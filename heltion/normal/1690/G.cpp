#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i += 1) cin >> a[i];
        set<int> s;
        for (int i = 1, p = INT_MAX; i <= n; i += 1) {
            if (a[i] < p) s.insert(i);
            p = min(p, a[i]);
        }
        for (int i = 0; i < q; i += 1) {
            int k, d;
            cin >> k >> d;
            a[k] -= d;
            int p = *prev(s.upper_bound(k));
            if (k == p or a[p] > a[k]) {
                s.insert(k);
                for (auto it = s.upper_bound(k); it != s.end(); it = s.erase(it))
                    if (a[*it] < a[k])  
                        break;
            } 
            cout << s.size() << " ";
        }
        cout << "\n";
    }
    return 0;   
}