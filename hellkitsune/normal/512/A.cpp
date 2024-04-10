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

int n;
string s[100];
vector<int> g[26];
bool l[26][26] = {};
bool f[100];
int len = 0;
int ans[26];

bool cmp(const int &lhs, const int &rhs) {
    return l[lhs][rhs];
}

void tryAdd(int a, int b) {
    if (l[a][b]) return;
    if (l[b][a]) {
        cout << "Impossible\n";
        exit(0);
    }
    l[a][b] = true;
    REP(i, 26) if (l[b][i]) tryAdd(a, i);
    REP(i, 26) if (l[i][a]) tryAdd(i, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> s[i];
    REP(i, n) len = max(len, (int)s[i].length());
    REP(i, n) s[i].resize(len, ' ');
    REP(i, n - 1) f[i] = true;
    REP(j, len) {
        REP(i, n) if (f[i]) {
            if (s[i][j] == ' ' || s[i + 1][j] == ' ') {
                if (s[i][j] != ' ') {
                    cout << "Impossible\n";
                    return 0;
                }
                if (s[i + 1][j] != ' ') f[i] = false;
                continue;
            }
            if (s[i][j] != s[i + 1][j]) {
                tryAdd(s[i][j] - 'a', s[i + 1][j] - 'a');
                f[i] = false;
            }
        }
    }
    REP(i, 26) ans[i] = i;
    while (true) {
        bool flag = false;
        REP(i, 26) for (int j = i + 1; j < 26; ++j) if (l[ans[j]][ans[i]]) {
            swap(ans[i], ans[j]);
            flag = true;
        }
        if (!flag) break;
    }
    REP(i, 26) for (int j = i + 1; j < 26; ++j) {
        assert(!l[ans[j]][ans[i]]);
    }
    REP(i, 26) cout << char(ans[i] + 'a');
    cout << endl;
    return 0;
}