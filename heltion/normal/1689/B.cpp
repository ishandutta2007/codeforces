#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> p(n + 1), q(n + 1);
        set<int> s;
        for (int i = 1; i <= n; i += 1) {
            s.insert(i);
            cin >> p[i];
        }
        if (n == 1) {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i <= n - 1; i += 1) {
            auto it = s.begin();
            if (*it == p[i]) it = next(it);
            q[i] = *it;
            s.erase(it);
        }
        q[n] = *s.begin();
        if (q[n] == p[n]) swap(q[n], q[n - 1]);
        for (int i = 1; i <= n; i += 1) cout << q[i] << " ";
        cout << "\n";
    }
    return 0;
}