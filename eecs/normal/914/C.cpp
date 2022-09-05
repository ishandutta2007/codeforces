#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
string s;
int k, ans, num[1010], f[1010][1010][2];

int main() {
    ios::sync_with_stdio(0);
    cin >> s >> k;
    if (!k) cout << "1\n", exit(0);
    for (int i = 2; i <= 1000; i++) {
        num[i] = num[__builtin_popcount(i)] + 1;
    }
    int len = s.size();
    f[0][0][0] = 1;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) for (int k : {0, 1}) {
            for (int l = 0; l <= (k ? 1 : (s[i] - '0')); l++) {
                (f[i + 1][j + l][k | (l < s[i] - '0')] += f[i][j][k]) %= P;
            }
        }
    }
    for (int i = 1; i <= 1000; i++) if (num[i] == k - 1) {
        (ans += f[len][i][0]) %= P;
        (ans += f[len][i][1]) %= P;
    }
    if (k == 1) ans = (ans + P - 1) % P;
    printf("%d\n", ans);
    return 0;
}