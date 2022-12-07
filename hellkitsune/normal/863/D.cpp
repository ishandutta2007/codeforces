#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q, m;
int a[200000];
int t[200000], from[200000], to[200000];
int b[100];

int main() {
    scanf("%d%d%d", &n, &q, &m);
    forn(i, n) scanf("%d", a + i);
    forn(i, q) {
        scanf("%d%d%d", t + i, from + i, to + i);
        --from[i], --to[i];
    }
    forn(i, m) scanf("%d", b + i), --b[i];
    for (int i = q - 1; i >= 0; --i) {
        int t = ::t[i];
        int from = ::from[i];
        int to = ::to[i];
        if (t == 1) {
            forn(j, m) {
                if (b[j] > from && b[j] <= to) {
                    --b[j];
                } else if (b[j] == from) {
                    b[j] = to;
                }
            }
        } else {
            forn(j, m) {
                if (b[j] >= from && b[j] <= to) {
                    b[j] = from + to - b[j];
                }
            }
        }
    }
    forn(i, m) printf("%d ", a[b[i]]);
    puts("");
    return 0;
}