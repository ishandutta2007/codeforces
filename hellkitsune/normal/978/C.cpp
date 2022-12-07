#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
LL a[200000];

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%I64d", a + i);
    LL sub = 0;
    int ind = 0;
    forn(i, m) {
        LL x;
        scanf("%I64d", &x), --x;
        while (x - sub >= a[ind]) {
            sub += a[ind];
            ++ind;
        }
        printf("%d %I64d\n", ind + 1, x - sub + 1);
    }
    return 0;
}