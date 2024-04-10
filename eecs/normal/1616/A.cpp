#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        map<int, int> mp;
        while (n--) {
            int x;
            scanf("%d", &x), mp[abs(x)]++;
        }
        int ans = 0;
        for (auto &p : mp) {
            ans += min(p.second, !p.first ? 1 : 2);
        }
        printf("%d\n", ans);
    }
    return 0;
}