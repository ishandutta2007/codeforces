#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    int lo = 0, hi = 1e7, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        int a = mid / 2;
        int b = mid / 3;
        int ab = mid / 6;
        a -= ab;
        b -= ab;
        int nn = max(0, n - a);
        int mm = max(0, m - b);
        if (nn + mm <= ab) hi = mid;
        else lo = mid + 1;
    }
    printf("%d\n", lo);
    return 0;
}