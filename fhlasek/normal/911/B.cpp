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

int main(int argc, char* argv[]) {
    int N, A, B;
    scanf("%d%d%d", &N, &A, &B);
    int ans = 0;
    FOR(x, 1, min(A, B)) {
        int serves = (A / x) + (B / x);
        if (serves >= N)
            ans = x;
    }
    printf("%d\n", ans);
    return 0;
}