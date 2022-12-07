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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, len;
string s, p;
int pos[1000000];
int h[2][1000001];
int mu[2][1000001];
int ha[2];

const int MOD = 1e9 + 7;
const int MO[2] = {1000000007, 1000000009};
const int MU[2] = {31, 47};

int getHash(int from, int to, int x) {
    int ret = (h[x][from] - h[x][to] * (LL)mu[x][to - from]) % MO[x];
    if (ret < 0) ret += MO[x];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    REP(i, 2) {
        mu[i][0] = 1;
        REP(j, n) mu[i][j + 1] = (mu[i][j] * (LL)MU[i]) % MO[i];
    }
    REP(i, m) cin >> pos[i], --pos[i];
    s.resize(n, char('z' + 1));
    int from = 0;
    len = (int)p.length();
    REP(i, m) {
        for (int ind = max(from, pos[i]); ind < pos[i] + len; ++ind)
            s[ind] = p[ind - pos[i]];
        from = pos[i] + len;
    }
    REP(z, 2) {
        h[z][n] = 0;
        for (int i = n - 1; i >= 0; --i)
            h[z][i] = ((LL)h[z][i + 1] * MU[z] + s[i] - 'a' + 3) % MO[z];
        ha[z] = 0;
        for (int i = len - 1; i >= 0; --i)
            ha[z] = ((LL)ha[z] * MU[z] + p[i] - 'a' + 3) % MO[z];
    }
    REP(i, m) REP(j, 2) if (getHash(pos[i], pos[i] + len, j) != ha[j]) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1;
    REP(i, n) if (s[i] == char('z' + 1)) {
        ans = ((LL)ans * 26) % MOD;
    }
    cout << ans << endl;
    return 0;
}