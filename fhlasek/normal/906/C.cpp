/* Written by Filip Hlasek 2017 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, b) for (int i = 0; i < (b); i++)

using namespace std;

#define MAXN 22
char steps[1 << MAXN], prev_id[1 << MAXN];
int prev_mask[1 << MAXN];

int N, M;
int g[MAXN];

int main(int argc, char* argv[]) {
    scanf("%d%d", &N, &M);
    REP(i, M) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--;
        v--;
        g[u] |= (1 << v);
        g[v] |= (1 << u);
    }
    REP(i, N) steps[1 << i] = 1;
    REP(mask, 1 << N) if (steps[mask]) {
        /*
          printf("mask: %d steps: %d prev_id: %d prev_mask: %d\n",
                 mask,
                 steps[mask],
                 prev_id[mask],
                 prev_mask[mask]);
                 */
        REP(i, N) {
            if (mask & (1 << i)) {
                int nmask = mask | g[i];
                if (!steps[nmask] || steps[nmask] > steps[mask] + 1) {
                    steps[nmask] = steps[mask] + 1;
                    prev_mask[nmask] = mask;
                    prev_id[nmask] = i;
                }
            } else {
                if ((mask & g[i]) == mask) {
                    int nmask = mask | (1 << i);
                    if (!steps[nmask] || steps[nmask] > steps[mask]) {
                        steps[nmask] = steps[mask];
                        prev_mask[nmask] = mask;
                    }
                }
            }
        }
    }
    int mask = (1 << N) - 1;
    printf("%d\n", steps[mask] - 1);
    vector<int> ans;
    while (steps[mask] > 1) {
        int nmask = prev_mask[mask];
        if (steps[nmask] != steps[mask]) {
            ans.push_back(prev_id[mask] + 1);
        }
        mask = nmask;
    }
    reverse(ans.begin(), ans.end());
    REP(i, ans.size()) {
        if (i)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}