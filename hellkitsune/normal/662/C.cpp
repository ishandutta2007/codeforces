#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[20][100005];
int a[100000];
int cost[1 << 20];
int ans[1 << 20];

mt19937 mt(123);

int myRand(int bound) {
    return mt() % bound;
}

int ord[20];

int calc(int mask) {
    int res = 0;
    REP(i, m) res += cost[a[i] ^ mask];
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, 1 << n) {
        cost[i] = __builtin_popcount(i);
        cost[i] = min(cost[i], n - cost[i]);
    }
    REP(i, n) scanf("%s", s[i]);
    REP(i, m) {
        REP(j, n) a[i] = (a[i] << 1) | (s[j][i] - '0');
    }
    memset(ans, -1, sizeof ans);
    REP(i, n) ord[i] = i;
    int best = n * m + 1;
    while (1000.0 * clock() / CLOCKS_PER_SEC < 5500) {
        int mask = mt() & ((1 << n) - 1);
        bool done = false;
        if (ans[mask] == -1) ans[mask] = calc(mask);
        while (!done) {
            done = true;
            random_shuffle(ord, ord + n, myRand);
            REP(ii, n) {
                int i = ord[ii];
                int nmask = mask ^ (1 << i);
                if (ans[nmask] == -1) ans[nmask] = calc(nmask);
                if (ans[nmask] < ans[mask]) {
                    done = false;
                    mask = nmask;
                }
            }
        }
        best = min(best, ans[mask]);
    }
    printf("%d\n", best);
    return 0;
}