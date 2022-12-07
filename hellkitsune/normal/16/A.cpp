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

string s[100];
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, n) cin >> s[i];
    bool flag = true;
    REP(i, n) {
        REP(j, m - 1) if (s[i][j] != s[i][j + 1]) {
            flag = false;
            break;
        }
        if (!flag) break;
    }
    if (flag) REP(i, n - 1) if (s[i][0] == s[i + 1][0]) {
        flag = false;
        break;
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}