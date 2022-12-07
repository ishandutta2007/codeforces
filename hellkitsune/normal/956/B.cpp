#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, dif;
int a[100005];
double ans = -10;

int main() {
    scanf("%d%d", &n, &dif);
    forn(i, n) scanf("%d", a + i);
    int r = 0;
    forn(i, n) {
        while (r + 1 < n && a[r + 1] - a[i] <= dif) {
            ++r;
        }
        if (r > i + 1) {
            ans = max(ans, double(a[r] - a[i + 1]) / (a[r] - a[i]));
        }
    }
    if (ans < -1) {
        printf("-1\n");
    } else {
        printf("%.15f\n", ans);
    }
    return 0;
}