#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int x, y, xx, yy;
vector<int> ans;

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d%d%d%d", &x, &y, &xx, &yy);
        int ans = 1;
        if (x % 2 != 0) ans += 1;
        if (y % 2 != 0) ans += 2;
        ::ans.pb(ans);
    }
    printf("YES\n");
    for (int x : ans) {
        printf("%d\n", x);
    }
    return 0;
}