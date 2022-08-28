#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[200010];
int cnt[200], n;
void rmain() {
    scanf("%s", s + 1);
    memset(cnt, 0, sizeof cnt);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) cnt[s[i]]++;
    for (int i = 1; i <= n; i++) {
        cnt[s[i]]--;
        if (cnt[s[i]] == 0) return puts(s + i), void();
    }
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}