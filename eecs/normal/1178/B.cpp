#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, pre[maxn], suf[maxn];
char s[maxn];
long long ans;

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + (s[i - 1] == 'v' && s[i] == 'v');
    }
    for (int i = n - 1; i; i--) {
        suf[i] = suf[i + 1] + (s[i + 1] == 'v' && s[i] == 'v');
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'o') {
            ans += 1LL * pre[i - 1] * suf[i + 1];
        }
    }
    printf("%lld\n", ans);
    return 0;
}