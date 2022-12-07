#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[300005], p[300005];
int nx[300005 * 70][2];
int cnt[300005 * 70];
int nodes = 1;

void add(int x) {
    int v = 0;
    ++cnt[v];
    for (int i = 29; i >= 0; --i) {
        int bit = (x >> i) & 1;
        if (nx[v][bit] == 0) {
            nx[v][bit] = nodes++;
        }
        v = nx[v][bit];
        ++cnt[v];
    }
}

int getBest(int x) {
    int v = 0;
    --cnt[v];
    int res = 0;
    for (int i = 29; i >= 0; --i) {
        res <<= 1;
        int bit = (x >> i) & 1;
        if (nx[v][bit] == 0 || cnt[nx[v][bit]] == 0) {
            v = nx[v][bit ^ 1];
            res |= 1;
        } else {
            v = nx[v][bit];
        }
        --cnt[v];
    }
    return res;
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) scanf("%d", p + i);
    forn(i, n) add(p[i]);
    forn(i, n) a[i] = getBest(a[i]);
    forn(i, n) printf("%d ", a[i]);
    puts("");
    return 0;
}