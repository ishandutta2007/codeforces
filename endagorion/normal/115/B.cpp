#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector< int > minw(n), maxw(n);
    vector< bool > lower(n);
    bool anyw = false;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        minw[i] = m;
        maxw[i] = -1;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'W') {
                minw[i] = min(minw[i], j);
                maxw[i] = max(maxw[i], j);
                anyw = true;
            }
        }
    }

    lower[n - 1] = false;
    for (int i = n - 2; i >= 0; --i) {
        lower[i] = lower[i + 1] | (minw[i + 1] != m);
    }
    int cur = 0;
    int ans = 0;
    int i = 0;
    for (i = 0; lower[i]; ++i) {
        if (i % 2 == 0) {
            int next = max(cur, maxw[i]);
            next = max(next, maxw[i + 1]);
            ans += next - cur + 1;
            cur = next;
        } else {
            int next = min(cur, minw[i]);
            next = min(next, minw[i + 1]);
            ans += cur - next + 1;
            cur = next;
        }
    }
    if (i % 2 == 0) {
        int next = max(cur, maxw[i]);
        ans += next - cur;
        cur = next;
    } else {
        int next = min(cur, minw[i]);
        ans += cur - next;
        cur = next;
    }
    if (!anyw) {
        cout << 0 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}