#include <bits/stdc++.h>
using namespace std;

int ans, a[10], b[10];
long long tmp[10][19], pw[19];

int main() {
    long long lb, ub;
    cin >> lb >> ub;
    string l = to_string(lb), r = to_string(ub);
    if (r == "1" + string(18, '0')) {
        if (l == r) cout << "1\n", exit(0);
        if (l != "1") ans++;
        r = string(18, '9');
    }
    while (l.size() < 18) l = "0" + l;
    for (int i = pw[0] = 1; i <= 18; i++) {
        pw[i] = pw[i - 1] * 10;
    }
    for (int i = 0; i <= 9; i++) {
        for (int j = 1; j <= 18; j++) {
            tmp[i][j] = tmp[i][j - 1] * 10 + i;
        }
    }
    function<void(int, int)> dfs = [&](int cur, int rem) {
        if (cur == 10) {
            if (rem) return;
            memcpy(b, a, sizeof(b));
            long long n = 0;
            for (int i = 0, d = 0; i < 18; i++) {
                bool flag = 0;
                for (int j = l[i] - '0'; j <= 9; j++) if (b[j]) {
                    b[j]--;
                    if (j == l[i] - '0') {
                        long long m = n * 10 + j;
                        for (int k = 9; ~k && m < lb; k--) {
                            m = m * pw[b[k]] + tmp[k][b[k]];
                        }
                        if (m < lb) { b[j]++; continue; }
                    }
                    n = n * 10 + j;
                    flag = 1, d |= j > l[i] - '0'; break;
                }
                if (!flag) return;
                if (d) {
                    for (int k = 0; k <= 9; k++) {
                        n = n * pw[b[k]] + tmp[k][b[k]];
                    }
                    break;
                }
            }
            ans += n <= ub; return;
        }
        for (int i = 0; i <= rem; i++) {
            a[cur] = i, dfs(cur + 1, rem - i);
        }
    };
    dfs(0, 18), printf("%d\n", ans);
    return 0;
}