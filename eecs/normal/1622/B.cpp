#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, p[maxn], q[maxn];
char s[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
        }
        scanf("%s", s + 1);
        vector<int> V0, V1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') V0.push_back(i);
            else V1.push_back(i);
        }
        sort(V0.begin(), V0.end(), [&](int x, int y) { return p[x] < p[y]; });
        sort(V1.begin(), V1.end(), [&](int x, int y) { return p[x] < p[y]; });
        int tot = 0;
        for (int x : V0) q[x] = ++tot;
        for (int x : V1) q[x] = ++tot;
        for (int i = 1; i <= n; i++) printf("%d ", q[i]);
        putchar('\n');
    }
    return 0;
}