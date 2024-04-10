#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
unsigned rem[32000];
unsigned pat[32][33] = {};
const unsigned ONE = 1;
int q[1000005], qh, qt;
int dist[1000005];
int a[1000];

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", a + i);
    int mn = a[0];
    REP(i, n) mn = min(mn, a[i]);
    REP(i, n) {
        int x = a[i] - mn;
        if (x == 0) continue;
        REP(j, 32) {
            pat[j][x >> 5] |= ONE << (x & 31);
            ++x;
        }
    }
    memset(rem, 255, sizeof rem);
    memset(dist, -1, sizeof dist);
    dist[0] = 0;
    q[0] = 0;
    qh = 0, qt = 1;
    while (qh < qt) {
        int v = q[qh++];
        int pn = v & 31;
        int ind = v >> 5;
        REP(i, 33) {
            unsigned bits = pat[pn][i] & rem[ind + i];
            if (!bits) continue;
            rem[ind + i] &= ~bits;
            int off = (ind + i) << 5;
            REP(j, 32) if (bits & (ONE << j)) {
                int nv = off + j;
                dist[nv] = dist[v] + 1;
                if (dist[nv] < k) {
                    q[qt++] = nv;
                }
            }
        }
    }
    for (int i = 0; i <= 1000000; ++i) if (dist[i] != -1) {
        printf("%d ", mn * k + i);
    }
    printf("\n");
    return 0;
}