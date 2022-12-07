#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    int ans = 0;
    REP(i, n) if (a[i] == 1 || a[i] == n) {
        ans = max(ans, i);
        ans = max(ans, n - 1 - i);
    }
    printf("%d\n", ans);
    return 0;
}