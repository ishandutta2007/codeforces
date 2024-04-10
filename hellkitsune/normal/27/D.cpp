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

int n, m;
bool g[100][100] = {};
int a[100], b[100];

string ans;

void go(int v, char c) {
    ans[v] = c;
    REP(i, m) if (!g[v][i]) {
        if (ans[i] == c) {
            cout << "Impossible\n";
            exit(0);
        } else if (ans[i] == '.') {
            go(i, (c == 'i') ? 'o' : 'i');
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m) cin >> a[i] >> b[i];
    REP(i, m) if (a[i] > b[i]) swap(a[i], b[i]);
    REP(i, m) REP(j, m) if (i != j) {
        g[i][j] = g[j][i] = true;
        if (a[j] > a[i] && a[j] < b[i] && (b[j] < a[i] || b[j] > b[i]))
            g[i][j] = g[j][i] = false;
        if (b[j] > a[i] && b[j] < b[i] && (a[j] < a[i] || a[j] > b[i]))
            g[i][j] = g[j][i] = false;
    }
    REP(i, m) g[i][i] = true;
    ans.resize(m, '.');
    REP(i, m) if (ans[i] == '.')
        go(i, 'i');
    cout << ans << '\n';
    return 0;
}