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

const int M = 15;

int main(int argc, char* argv[]) {
    int k[3];
    scanf("%d%d%d", k + 0, k + 1, k + 2);

    REP(a, M) REP(b, M) REP(c, M) {
        bool ok = true;
        REP(i, M) {
            if ((i - a) % k[0] && (i - b) % k[1] && (i - c) % k[2]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");

    return 0;
}