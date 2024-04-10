#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int n, m, c;
int a[MAXN];

bool check() {
    for (int i = 0; i < n; ++i) if (!a[i]) return 0;
    for (int i = 0; i < n - 1; ++i) if (a[i] > a[i + 1]) return 0;
    return 1;
}   

signed main() {
    cin >> n >> m >> c;
    int pref = 0, post = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (x <= c / 2) {
            if (pref == 0 || a[pref - 1] <= x) {
                a[pref] = x;
                cout << pref + 1 << '\n';
                fflush(stdout);
                ++pref;
            }   
            else {
                for (int t = 0; ; ++t) {
                    if (x < a[t]) {
                        a[t] = x;
                        cout << t + 1 << '\n';
                        fflush(stdout);
                        ++t;
                        break;
                    }
                }
            }
        }
        else {
            if (post == 0 || a[n - post] >= x) {
                a[n - post - 1] = x;
                cout << n - post << '\n';
                fflush(stdout);
                ++post;
            }
            else {
                for (int t = n - 1; t >= 0; --t) {
                    if (x > a[t]) {
                        a[t] = x;
                        cout << t + 1 << '\n';
                        fflush(stdout);
                        ++t;
                        break;
                    }   
                }
            }
        }
        if (pref + post == n) exit(0);
    }
    return 0;
}