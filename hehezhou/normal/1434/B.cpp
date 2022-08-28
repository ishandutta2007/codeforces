#include <bits/stdc++.h>
using namespace std;
#define gg (puts("NO"), exit(0))
int n;
set < int > rest;
char s[10];
int ans[200010];
int sta[100010], top, k[100010];
int main() {
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%s", s);
        if (s[0] == '+') {
            rest.insert(i);
        }
        else {
            int x;
            scanf("%d", &x);
            x = -x;
            int lst = lower_bound(sta + 1, sta + 1 + top, x) - sta - 1;
            lst = k[lst];
            auto ite = rest.lower_bound(lst);
            if (ite == rest.end()) gg;
            ans[*ite] = -x;
            rest.erase(ite);
            while (top && sta[top] > x) top--;
            sta[++top] = x;
            k[top] = i;
        }
    }
    puts("YES");
    for (int i = 1; i <= n + n; i++) if (ans[i]) printf("%d ", ans[i]);
    puts("");
}