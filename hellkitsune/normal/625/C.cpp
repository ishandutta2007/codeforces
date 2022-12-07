#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[500][500];

int main() {
    scanf("%d%d", &n, &k);
    int cur = 0;
    REP(i, k - 1) {
        REP(j, n) a[j][i] = ++cur;
    }
    int sum = 0;
    REP(i, n) for (int j = k - 1; j < n; ++j) {
        a[i][j] = ++cur;
        if (j == k - 1) sum += a[i][j];
    }
    printf("%d\n", sum);
    REP(i, n) {
        REP(j, n) printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}