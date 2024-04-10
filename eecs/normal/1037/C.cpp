#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, ans;
char s[maxn], t[maxn];

int main() {
    scanf("%d %s %s", &n, s + 1, t + 1);
    for (int i = 1; i <= n; i++) if (s[i] ^ t[i]) {
        ans++;
        if (s[i + 1] ^ t[i + 1] && s[i] ^ s[i + 1]) i++;
    }
    printf("%d\n", ans);
    return 0;
}