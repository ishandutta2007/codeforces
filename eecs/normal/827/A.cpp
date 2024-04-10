#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000010;
int n, nxt[maxn];
char s[maxn], t[maxn];

int find(int x) {
    return x == nxt[x] ? x : nxt[x] = find(nxt[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2000001; i++) {
        nxt[i] = i;
    }
    int mx = 0;
    while (n--) {
        scanf("%s", s + 1);
        int l = strlen(s + 1), k;
        scanf("%d", &k);
        while (k--) {
            int p; scanf("%d", &p);
            mx = max(mx, p + l - 1);
            for (int i = find(p); i <= p + l - 1; i = find(i)) {
                t[i] = s[i - p + 1], nxt[i] = i + 1;
            }
        }
    }
    for (int i = 1; i <= mx; i++) {
        putchar(max('a', t[i]));
    }
    return 0;
}