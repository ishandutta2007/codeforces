#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, a[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    int cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        int tmp = a[i];
        a[i] = max(0, cur - a[i]);
        cur = max(cur, tmp + 1);
    }
    REP(i, n) printf("%d ", a[i]);
    printf("\n");
    return 0;
}