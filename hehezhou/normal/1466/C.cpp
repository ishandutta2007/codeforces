#include <bits/stdc++.h>
using namespace std;
char s[100010];
int t;
inline void rmain() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i - 1 > 0 && s[i] == s[i - 1] || i - 2 > 0 && s[i] == s[i - 2]) {
            s[i] = -1;
            ans++;
        } 
    }
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &t);
    while (t--) rmain();
}