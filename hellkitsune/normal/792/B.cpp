#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[100];
int b[100], c[100];

int main() {
    scanf("%d%d", &n, &k);
    forn(i, k) {
        scanf("%d", a + i);
    }
    forn(i, n) {
        b[i] = i + 1;
    }
    forn(_, k) {
        int ind = a[_] % n;
        printf("%d ", b[ind]);
        int nn = 0;
        for (int i = ind + 1; i < n; ++i) {
            c[nn++] = b[i];
        }
        for (int i = 0; i < ind; ++i) {
            c[nn++] = b[i];
        }
        n = nn;
        memcpy(b, c, sizeof b);
    }
    puts("");
    return 0;
}