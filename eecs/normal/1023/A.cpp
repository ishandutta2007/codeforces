#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m;
char s[maxn], t[maxn];

int main() {
    scanf("%d %d %s %s", &n, &m, s + 1, t + 1);
    if (m < n - 1) puts("NO"), exit(0);
    int pos = -1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '*') { pos = i; break; }
    }
    if (!~pos) {
        if (n ^ m) puts("NO"), exit(0);
        bool flag = 1;
        for (int i = 1; i <= n; i++) flag &= (s[i] == t[i]);
        puts(flag ? "YES" : "NO"), exit(0);
    }
    bool flag = 1;
    for (int i = 1; i < pos; i++) {
        flag &= (s[i] == t[i]);
    }
    for (int i = pos + 1; i <= n; i++) {
        flag &= (s[i] == t[m - (n - i)]);
    }
    puts(flag ? "YES" : "NO");
    return 0;
}