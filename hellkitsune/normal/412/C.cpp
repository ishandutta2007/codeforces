#include <cstdio>
#include <cmath>
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

int n, m;
string s[100000];
string ans;

int main() {
    cin >> n;
    REP(i, n)
        cin >> s[i];
    m = s[0].length();
    ans.assign(m, '*');
    REP(i, n) REP(j, m)
        if (s[i][j] != '?') {
            if (ans[j] == '*')
                ans[j] = s[i][j];
            else if (ans[j] != s[i][j])
                ans[j] = '?';
        }
    REP(i, m)
        if (ans[i] == '*')
            ans[i] = 'x';
    cout << ans << "\n";
    return 0;
}