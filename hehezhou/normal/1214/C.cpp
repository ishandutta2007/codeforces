#include <bits/stdc++.h>
using namespace std;
char s[200010];
int n;
int main() {
    scanf("%d%s", &n, s);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) if(s[i] == '(') cnt1++, s[i] = 1; else cnt2++, s[i] = -1;
    if(cnt1 != cnt2) return puts("No"), 0;
    int tag;
    for(int i = 0; i < n; i++) if(s[i] == -1) {
        tag = i;
        break;
    }
    int ans = 0, now = 0;
    for(int i = 0; i < n; i++) {
        if(i == tag) continue;
        now += s[i];
        if(now < 0) break;
        if(i == n - 1) ans = 1;
    }
    for(int i = 0; i < n; i++) if(s[i] == 1) tag = i;
    now = 1;
    for(int i = 0; i < n; i++) {
        if(i == tag) continue;
        now += s[i];
        if(now < 0) break;
        if(i == n - 1) ans = 1;
    }
    puts(ans ? "Yes" : "No");
}