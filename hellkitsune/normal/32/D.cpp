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

int n, m, k;
string s[300];
bool a[300][300];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    REP(i, n) cin >> s[i];
    REP(i, n) REP(j, m) a[i][j] = s[i][j] == '*';
    for (int d = 1; d < 200; ++d) {
        for (int i = d; i < n - d; ++i) {
            for (int j = d; j < m - d; ++j) {
                if (a[i][j] && a[i - d][j] && a[i + d][j] && a[i][j - d] && a[i][j + d]) {
                    if (--k == 0) {
                        ++i;
                        ++j;
                        cout << i << ' ' << j << endl;
                        cout << i - d << ' ' << j << endl;
                        cout << i + d << ' ' << j << endl;
                        cout << i << ' ' << j - d << endl;
                        cout << i << ' ' << j + d << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}