#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int n, ans;
char s[maxn];

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        int l = 0, q = 0;
        for (int j = i; j <= n; j++) {
            if (s[j] == '(') l++;
            if (s[j] == ')') l--;
            if (s[j] == '?') q++;
            if (l < 0) break;
            if (l < q) q--, l++;
            if (l == q) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}