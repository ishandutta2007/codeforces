#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int n;
char s[maxn], t[maxn];

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (s[1] ^ s[i]) cnt++;
    }
    if (!cnt) puts("Impossible"), exit(0);
    if (cnt == 1 && n % 2 == 1 && s[1] ^ s[(n + 1) / 2]) puts("Impossible"), exit(0);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) t[j - i] = s[j];
        for (int j = 1; j <= i; j++) t[n - i + j] = s[j];
        bool flag = 0;
        for (int j = 1; j <= n; j++) flag |= (s[j] != t[j]);
        for (int j = 1; j <= n; j++) if (t[j] ^ t[n + 1 - j]) { flag = 0; break; }
        if (flag) puts("1"), exit(0);
    }
    puts("2");
    return 0;
}