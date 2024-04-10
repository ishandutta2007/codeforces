#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[123456];

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%d", a + i), --a[i];
    forn(_, m) {
        int from, to, x;
        scanf("%d%d%d", &from, &to, &x);
        --from, --to, --x;
        if (x < from || x > to) {
            printf("No\n");
            continue;
        }
        int pos = x - from;
        x = a[x];
        for (int i = from; i <= to; ++i) {
            if (a[i] < x) {
                --pos;
            }
        }
        if (pos == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}