#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int n, p[26][maxn][26];
char s[maxn], t[maxn];
double ans;

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            t[j - i] = s[j];
        }
        for (int j = 1; j <= i; j++) {
            t[j + n - i] = s[j];
        }
        for (int j = 1; j <= n; j++) {
            p[t[1] - 'a'][j][t[j] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        int mx = 0;
        for (int j = 1; j <= n; j++) {
            int s = 0;
            for (int k = 0; k < 26; k++) {
                s += (p[i][j][k] == 1);
            }
            mx = max(mx, s);
        }
        ans += 1.0 * mx / n;
    }
    printf("%.7f\n", ans);
    return 0;
}