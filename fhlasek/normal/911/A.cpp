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

#define MAXN 1111111
int A[MAXN];

int main(int argc, char* argv[]) {
    int N;
    scanf("%d", &N);
    REP(i, N) scanf("%d", A + i);
    int m = A[0];
    REP(i, N) m = min(m, A[i]);
    int ans = N, last = -N;
    REP(i, N) if (A[i] == m) {
        ans = min(ans, i - last);
        last = i;
    }
    printf("%d\n", ans);

    return 0;
}