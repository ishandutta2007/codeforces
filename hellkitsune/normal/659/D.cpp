#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, x, y, xx, yy;
int pre = -100;

int main() {
    scanf("%d%d%d", &n, &x, &y);
    int ans = 0;
    REP(i, n) {
        scanf("%d%d", &xx, &yy);
        int cur;
        if (yy > y) cur = 0;
        else if (xx > x) cur = 1;
        else if (yy < y) cur = 2;
        else cur = 3;
        if (cur == (pre + 3) % 4) ++ans;
        x = xx;
        y = yy;
        pre = cur;
    }
    printf("%d\n", ans);
    return 0;
}