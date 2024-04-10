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

#define MAXN 2222
int A[MAXN];
int N;

int main(int argc, char* argv[]) {
    scanf("%d", &N);
    REP(i, N) scanf("%d", A + i);
    int ans = 0;
    REP(i, N) REP(j, i) if (A[j] > A[i]) ans = !ans;
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        int n = r - l + 1;
        ans ^= n * (n - 1) / 2 % 2;
        printf("%s\n", ans ? "odd" : "even");
    }
    return 0;
}