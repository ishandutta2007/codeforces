#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> indices(n + 3);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            indices[a[i]].push_back(i);
        }
        for (int i = 0; i <= n; ++i) reverse(all(indices[i]));

        vector<int> b;
        for (int start = 0; start < n; ) {
            int lastPicked = -1;
            int pushMex = -1;
            for (int mex = 0; ; ++mex) {
                while (!indices[mex].empty() && indices[mex].back() < start)
                    indices[mex].pop_back();
                if (indices[mex].empty()) {
                    pushMex = mex;
                    break;
                }
                lastPicked = max(lastPicked, indices[mex].back());
                indices[mex].pop_back();
            }
            if (lastPicked == -1) lastPicked = start;
            b.push_back(pushMex);
            start = lastPicked + 1;
        }
        cout << b.size() << '\n';
        for (int x : b) cout << x << ' ';
        cout << '\n';
    }
}