#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
deque<int> d[250];
const int LEN = 512;
const int MASK = 511;
const int BITS = 9;
int cnt[250][100001] = {};

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        d[i >> BITS].pb(x);
        ++cnt[i >> BITS][x];
    }
    scanf("%d", &q);
    int lastAns = 0;
    REP(i, q) {
        int qt, l, r, k;
        scanf("%d%d%d", &qt, &l, &r);
        l = (l + lastAns - 1) % n;
        r = (r + lastAns - 1) % n;
        if (l > r) swap(l, r);
        if (qt == 1) {
            int rem = d[r >> BITS][r & MASK];
            --cnt[r >> BITS][rem];
            for (int j = r; j > l; ) {
                if ((j & MASK) == MASK && j - l >= LEN) {
                    d[j >> BITS].pop_back();
                    int val = d[(j >> BITS) - 1].back();
                    ++cnt[j >> BITS][val];
                    --cnt[(j >> BITS) - 1][val];
                    d[j >> BITS].push_front(val);
                    j -= LEN;
                } else if (j & MASK) {
                    d[j >> BITS][j & MASK] = d[j >> BITS][(j & MASK) - 1];
                    --j;
                } else {
                    int val = d[(j >> BITS) - 1].back();
                    ++cnt[j >> BITS][val];
                    --cnt[(j >> BITS) - 1][val];
                    d[j >> BITS][0] = val;
                    --j;
                }
            }
            d[l >> BITS][l & MASK] = rem;
            ++cnt[l >> BITS][rem];
        } else {
            scanf("%d", &k);
            k = (k + lastAns - 1) % n + 1;
            int ans = 0;
            for (int i = l; i <= r; ) {
                if ((i & MASK) == 0 && (i | MASK) <= r) {
                    ans += cnt[i >> BITS][k];
                    i += LEN;
                } else {
                    ans += d[i >> BITS][i & MASK] == k;
                    ++i;
                }
            }
            lastAns = ans;
            printf("%d\n", ans);
        }
    }
    return 0;
}