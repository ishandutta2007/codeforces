#include <iostream>
#include <vector>

using namespace std;

const int INF = 2e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> l(n), r(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i] >> c[i];
        }
        int L = l[0], R = r[0], c1 = c[0], c2 = c[0];
        vector<int> ans(n);
        ans[0] = c1;
        for (int i = 1; i < n; ++i) {
            if (l[i] < L || (l[i] == L && c1 > c[i])) {
                L = l[i];
                c1 = c[i];
            }
            if (r[i] > R || (r[i] == R && c2 > c[i])) {
                R = r[i];
                c2 = c[i];
            }
            ans[i] = c1 + c2;
        }
        L = l[0], R = r[0];
        int C = c[0];
        for (int i = 1; i < n; ++i) {
            if ((l[i] < L && r[i] < R) || (l[i] > L && r[i] > R)) {
                L = min(L, l[i]);
                R = max(R, r[i]);
                C = INF;
            } else {
                bool expand = (l[i] < L || r[i] > R);
                if (expand) {
                    L = min(L, l[i]);
                    R = max(R, r[i]);
                    C = c[i];
                }
                if (l[i] == L && r[i] == R) {
                    C = min(C, c[i]);
                }
            }
            L = min(L, l[i]);
            R = max(R, r[i]);
            ans[i] = min(ans[i], C);
        }
        for (int x : ans) {
            cout << x << '\n';
        }
    }
    return 0;
}