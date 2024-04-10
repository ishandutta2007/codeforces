#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int cur = 0, mx;
int a[10] = {};

int main() {
    scanf("%d%d", &n, &k);
    mx = n * 10;
    REP(i, n) {
        int x;
        scanf("%d", &x);
        cur += x / 10;
        ++a[x % 10];
    }
    for (int i = 9; i > 0; --i) {
        int x = 10 - i;
        int delta = min(a[i], k / x);
        cur += delta;
        k -= x * delta;
    }
    cur += k / 10;
    cur = min(cur, mx);
    printf("%d\n", cur);
    return 0;
}