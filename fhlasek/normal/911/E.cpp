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

#define MAXN 222222
int N, K;
int P[MAXN];
int A[MAXN];

stack<int> s;
bool solve() {
    int done = 0;
    REP(i, K) {
        while (!s.empty() && s.top() == done + 1) {
            s.pop();
            done++;
        }
        if (!s.empty() && s.top() < P[i]) {
            return false;
        }
        s.push(P[i]);
        A[i] = P[i];
    }
    FOR(i, K, N - 1) {
        while (!s.empty() && s.top() == done + 1) {
            s.pop();
            done++;
        }
        if (s.empty()) {
            A[i] = N;
        } else {
            A[i] = s.top() - 1;
        }
        s.push(A[i]);
    }
    return true;
}

int main(int argc, char* argv[]) {
    scanf("%d%d", &N, &K);
    REP(i, K) scanf("%d", P + i);
    if (solve()) {
        REP(i, N) {
            if (i)
                printf(" ");
            printf("%d", A[i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
    return 0;
}