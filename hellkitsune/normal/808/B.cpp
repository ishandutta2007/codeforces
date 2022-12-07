#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[200000];

int main() {
    scanf("%d%d", &n, &k);
    forn(i, n) scanf("%d", a + i);
    LL sum = 0;
    double res = 0;
    forn(i, k) sum += a[i];
    forn(i, n - k + 1) {
        res += sum;
        if (i < n - k) {
            sum -= a[i];
            sum += a[i + k];
        }
    }
    res /= n - k + 1;
    printf("%.11f\n", res);
    return 0;
}