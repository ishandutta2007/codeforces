/* Written by Filip Hlasek 2018 */
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

#define MAXN 2222222
bool composite[MAXN];

int solve2(int x2, int p2) {
    int ans = x2;
    FOR(x1, x2 - p2 + 1, min(x2 - p2 + 1000, x2 - 1)) {
        ans = min(ans, x1);
        for (int p1 = 2; p1 * p1 <= x1; ++p1) {
            if (x1 % p1 == 0) {
                if (!composite[p1]) {
                    ans = min(ans, x1 - p1 + 1);
                }
                if (!composite[x1 / p1]) {
                    ans = min(ans, x1 - x1 / p1 + 1);
                }
            }
        }
    }
    return ans;
}

int main(int argc, char* argv[]) {
    int last = 0, gap = 0;
    FOR(i, 2, MAXN - 1) if (!composite[i]) {
        if (i - last > gap) {
            gap = i - last;
        }
        last = i;
        for (int j = 2 * i; j < MAXN; j += i) {
            composite[j] = true;
        }
    }

    int x2;
    scanf("%d", &x2);
    int ans = x2;
    for (int p2 = 2; p2 * p2 <= x2; p2++) {
        if (x2 % p2 == 0) {
            if (!composite[p2]) {
                ans = min(ans, solve2(x2, p2));
            }
            if (!composite[x2 / p2] && p2 * p2 < x2) {
                ans = min(ans, solve2(x2, x2 / p2));
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}