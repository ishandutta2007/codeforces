#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K;
char s[maxn];

int main() {
    scanf("%d %d %s", &n, &K, s + 1);
    int c0 = 0, c1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') {
            if (++c0 <= K / 2) putchar('(');
        } else {
            if (++c1 <= K / 2) putchar(')');
        }
    }
    return 0;
}