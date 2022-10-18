#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[4004004];
int b[4004004];
int last[4004004];
int count_s[4004004];

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        fill(a, a + n + 10, 0); // count
        fill(b, b + n + 10, 0); // count of counts
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            --x;
            ++a[x];
        }
        for (int i = 0; i < n; ++i) {
            ++b[a[i]];
        }
        int num = 0;
        fill(last, last + n + 10, -1);
        fill(count_s, count_s + n + 10, 0);
        for (int i = 1; i <= n; ++i) {
            if (b[i]) {
                ++num;
                for (int j = 1; (j - 2) * (j - 1) <= i; ++j) {
                    last[j] = i;
                    ++count_s[j];
                }
                for (int u = 1; ; ++u) {
                    int o = i / u;
                    int r = i % u;
                    if (r == 0) {
                        if (last[o] != i) {
                            last[o] = i;
                            ++count_s[o];
                        }
                        ++o;
                        if (last[o] != i) {
                            last[o] = i;
                            ++count_s[o];
                        }
                    } else {
                        ++o;
                        if ((o - 2) * (ll)(o - 1) <= i) {
                            break;
                        }
                        if (last[o] != i) {
                            last[o] = i;
                            ++count_s[o];
                        }
                    }
                }
            }
        }
        int best_s = 1;
        for (int i = n; i >= 1; --i) {
            if (count_s[i] == num) {
                best_s = i;
                break;
            }
        }
//        cerr << "s = " << best_s << endl;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (b[i] > 0) {
                ans += b[i] * ((i + best_s - 1) / best_s);
//                cerr << "for " << i << " x" << b[i] << ": " << ((i + best_s - 1) / best_s) << endl;
            }
        }
        cout << ans << "\n";
    }
}