#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n;
char s[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s", &n, s + 1);
        int k = 2;
        while (k <= n && (s[k] < s[k - 1] || s[k - 1] != s[1] && s[k] <= s[k - 1])) k++;
        for (int i = 1; i < k; i++) putchar(s[i]);
        for (int i = k - 1; i; i--) putchar(s[i]);
        putchar('\n');
    }
    return 0;
}