#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a, p = 101, np;

int main() {
    scanf("%d", &n);
    int ans = 0;
    REP(i, n) {
        scanf("%d%d", &a, &np);
        p = min(p, np);
        ans += a * p;
    }
    printf("%d\n", ans);
    return 0;
}