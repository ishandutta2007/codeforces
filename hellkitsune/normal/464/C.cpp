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

string s;
int n, q;
string t[100001];
int d[100001];
int nx[100001][10];
PII me[10][100001];

const int MOD = 1e9 + 7;

PII go(int dig, int x) {
    if (me[dig][x].first != -1) return me[dig][x];
    if (nx[x][dig] == -1) return me[dig][x] = mp(dig, 10);
    int ret = 0, mult = 1;
    int xx = nx[x][dig];
    REP(i, t[xx].size()) {
        int ddig = t[xx][i] - '0';
        PII tmp = go(ddig, xx);
        ret = ((LL)ret * tmp.second + tmp.first) % MOD;
        mult = ((LL)mult * tmp.second) % MOD;
    }
    return me[dig][x] = mp(ret, mult);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> t[i];
        d[i] = t[i][0] - '0';
        t[i].erase(0, 3);
    }
    REP(i, 10) nx[q][i] = -1;
    for (int i = q - 1; i >= 0; --i) {
        REP(j, 10) nx[i][j] = nx[i + 1][j];
        nx[i][d[i + 1]] = i + 1;
    }
    REP(i, 10) for (int j = 0; j <= q; ++j) me[i][j] = mp(-1, -1);
    int ret = 0;
    REP(i, n) {
        PII tmp = go(s[i] - '0', 0);
        ret = ((LL)ret * tmp.second + tmp.first) % MOD;
    }
    cout << ret << '\n';
    return 0;
}