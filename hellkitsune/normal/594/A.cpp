#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int x[200000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", x + i);
    sort(x, x + n);
    int cnt = n - (n - 1) / 2;
    int best = 1e9 + 5;
    for (int i = 0; i + cnt <= n; ++i) {
        best = min(best, x[i + cnt - 1] - x[i]);
    }
    printf("%d\n", best);
    return 0;
}