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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, nn;
char s[200];
const int MOD = 51123987;
const int INF = 1e9;
int p[3];
int nxt[3][200];
int d[151][2][52][52] = {};

inline void add(int &a, const int &b) {
    a += b;
    if (a > MOD) a -= MOD;
}

int main() {
    scanf("%d%s", &n, s + 1);
    int del = 0;
    for (int i = 2; i <= n; ++i) if (s[i] == s[i - 1])
        ++del;
    else
        s[i - del] = s[i];
    nn = n;
    n -= del;
    REP(i, 3) p[i] = INF;
    for (int i = n; i >= 0; --i) {
        if (i) p[s[i] - 'a'] = i;
        REP(j, 3) nxt[j][i] = p[j];
    }
    d[0][0][0][0] = 1;
    int N = (nn + 2) / 3;
    int ans = 0;
    REP(a, N + 1) {
        REP(i, n + 1) REP(b, N + 1) REP(c, N + 1) {
            if (nxt[0][i] != INF) add(d[nxt[0][i]][1][b][c],     d[i][0][b][c]);
            if (nxt[1][i] != INF) add(d[nxt[1][i]][0][b + 1][c], d[i][0][b][c]);
            if (nxt[2][i] != INF) add(d[nxt[2][i]][0][b][c + 1], d[i][0][b][c]);
        }
        if (a >= N - 1) for (int b = N - 1; b <= N; ++b) for (int c = N - 1; c <= N; ++c) {
            if (a + b + c == nn) for (int i = 1; i <= n; ++i)
                add(ans, d[i][0][b][c]);
        }
        REP(i, n + 1) REP(b, N + 1) REP(c, N + 1)
            d[i][0][b][c] = d[i][1][b][c], d[i][1][b][c] = 0;
    }
    printf("%d\n", ans);
    return 0;
}