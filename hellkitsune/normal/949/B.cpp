#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n, x;
int q;

int main() {
    scanf("%I64d%d", &n, &q);
    forn(_, q) {
        scanf("%I64d", &x);
        while (!(x & 1)) {
            x += n - (x >> 1);
        }
        printf("%I64d\n", (x + 1) / 2);
    }
    return 0;
}