//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<int> p(n, -1);
        vector<bool> was(n);

        auto query = [&](int x) {
            cout << "? " << (x + 1) << endl;
            cin >> x;
            --x;
            was[x] = true;
            return x;
        };

        for (int i = 0; i < n; ++i) {
            if (was[i]) continue;
            vector<int> cycle{query(i)};
            while (true) {
                int x = query(i);
                cycle.push_back(x);
                if (x == cycle[0])
                    break;
            }
            int k = (int)cycle.size();
            for (int j = 0; j + 1 < k; ++j)
                p[cycle[j]] = cycle[j + 1];
        }

        cout << '!';
        for (int x : p)
            cout << ' ' << (x + 1);
        cout << endl;
    }
}