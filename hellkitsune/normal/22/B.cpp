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
string s[26];
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, n) cin >> s[i], s[i] += '1';
    s[n].resize(m + 1, '1');
    REP(i, n) REP(j, m) if (s[i][j] == '0') {
        int ind = i;
        do {
            int cnt = 1;
            for (int jj = j + 1; ; ++jj) {
                bool flag = true;
                for (int ii = i; ii <= ind; ++ii) if (s[ii][jj] == '1') {
                    flag = false;
                    break;
                }
                if (flag) ++cnt;
                else break;
            }
            ans = max(ans, (cnt + ind - i + 1) * 2);
        } while (s[++ind][j] == '0');
    }
    cout << ans << '\n';
    return 0;
}