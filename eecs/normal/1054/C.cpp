#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, l[maxn], r[maxn], a[maxn];
bool vis[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &l[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &r[i]);
    }
    int num = n;
    while (1) {
        bool flag = 0;
        vector<int> pos;
        for (int i = 1; i <= n; i++) if (!vis[i]) {
            if (!l[i] && !r[i]) pos.push_back(i), vis[i] = 1, flag = 1;
        }
        if (!flag) break;
        for (int x : pos) {
            a[x] = num;
            for (int i = 1; i < x; i++) if (!vis[i]) {
                if (!r[i]) puts("NO"), exit(0);
                r[i]--;
            }
            for (int i = x + 1; i <= n; i++) if (!vis[i]) {
                if (!l[i]) puts("NO"), exit(0);
                l[i]--;
            }
        }
        num--;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) puts("NO"), exit(0);
    }
    puts("YES");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}