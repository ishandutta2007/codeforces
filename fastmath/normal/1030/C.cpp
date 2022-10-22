#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101;

int n;
int a[MAXN], b[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }

    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            b[m] = a[i];
            ++m;
        }
    }
    
    n = m;
    for (int i = 0; i < n; ++i) a[i] = b[i];

    if (n == 0) {
        cout << "YES\n";
        exit(0);
    }

    int t = 0;
    for (int i = 0; i < n; ++i) t += a[i];

    for (int sum = 1; sum < t; ++sum) {
        int u = -1;
        bool ch = 1;
        while (u + 1 < n) {
            int curr = 0;
            while (curr < sum && u + 1 < n) {
                ++u;
                curr += a[u];
            }
            if (curr != sum) ch = 0;
        }
        if (ch) {
            cout << "YES\n";
            exit(0);
        }
    }

    cout << "NO\n";
    return 0;
}