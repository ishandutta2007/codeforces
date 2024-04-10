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

string s;
int n;
int a[50], b[50], alen = 0, blen = 0;
bool d[51][51][26] = {}, e[51][51][26] = {};
int z[50], p[50], q[50];

void parseString(string &s, int &len, int (&a)[50]) {
    len = (int)s.length();
    REP(i, len) a[i] = s[i] - 'a';
}

void solve(int (&a)[50], int len, bool (&d)[51][51][26]) {
    REP(i, len) d[i][i][a[i]] = true;
    for (int k = 2; k <= len; ++k) {
        REP(from, len - k + 1) {
            int to = from + k - 1;
            for (int mid = from; mid < to; ++mid) {
                REP(i, n) if (d[from][mid][p[i]] && d[mid + 1][to][q[i]]) {
                    d[from][to][z[i]] = true;
                }
            }
        }
    }
}

int ans[51][51];
const int INF = 1e9;

int main() {
    cin >> s;
    parseString(s, alen, a);
    cin >> s;
    parseString(s, blen, b);
    cin >> n;
    REP(i, n) {
        cin >> s;
        z[i] = s[0] - 'a';
        p[i] = s[3] - 'a';
        q[i] = s[4] - 'a';
    }
    solve(a, alen, d);
    solve(b, blen, e);
    REP(i, alen + 1) REP(j, blen + 1) ans[i][j] = INF;
    ans[0][0] = 0;
    REP(i, alen) REP(j, blen) if (ans[i][j] < INF) {
        for (int ilen = 1; ilen <= alen - i; ++ilen) for (int jlen = 1; jlen <= blen - j; ++jlen) {
            bool ok = false;
            REP(z, 26) if (d[i][i + ilen - 1][z] && e[j][j + jlen - 1][z]) {
                ok = true;
                break;
            }
            if (ok) ans[i + ilen][j + jlen] = min(ans[i + ilen][j + jlen], ans[i][j] + 1);
        }
    }
    if (ans[alen][blen] == INF) ans[alen][blen] = -1;
    cout << ans[alen][blen] << endl;
    return 0;
}