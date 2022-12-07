#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, t;

int main() {
    scanf("%d%d", &n, &t);
    if (n == 1 && t == 10) {
        printf("-1\n");
        return 0;
    }
    int rem = 0;
    REP(i, n - 1) {
        printf("1");
        rem = (10 * rem + 1) % t;
    }
    if (t == 10) {
        printf("0\n");
    } else {
        rem = 10 * rem % t;
        printf("%d\n", t - rem);
    }
    return 0;
}