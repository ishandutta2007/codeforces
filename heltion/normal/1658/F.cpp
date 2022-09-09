#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> ps(n);
        for (int i = 0; i < n; i += 1) {
            ps[i] = s[i] - '0';
            if (i) ps[i] += ps[i - 1];
        }
        int k = ps.back();
        if ((LL)k * m % n) {
            cout << "-1\n";
            continue;;
        }
        int y = (LL)k * m / n;
        int done = 0;
        for (int i = m - 1; i < n and not done; i += 1) {
            if (ps[i] - (i >= m ? ps[i - m] : 0) == y) {
                cout << "1\n" << i - m + 2 << " " << i + 1 << "\n";
                done = 1;
            }
        }
        int rm = n - m;
        for (int i = rm; i + 1 < n and not done; i += 1) {
            if (ps[i - rm] + ps.back() - ps[i] == y) {
                //cout << i << " " << i - rm << " " << ps[i - rm] << " " << ps.back() - ps[i] << "\n";
                cout << "2\n" << 1 << " " << i - rm + 1 << "\n" << i + 2 << " " << n << "\n";
                done = 1;
            }
        }
        assert(done);
    }
    return 0;
}