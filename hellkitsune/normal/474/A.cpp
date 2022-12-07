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
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

string a, s;
string f[3] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./}"};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> s;
    if (a[0] == 'R') {
        REP(k, s.length()) {
            bool flag = true;
            REP(i, 3) if (flag) REP(j, 10) if (f[i][j] == s[k]) {
                s[k] = f[i][j - 1];
                flag = false;
                break;
            }
        }
    } else {
        REP(k, s.length()) {
            bool flag = true;
            REP(i, 3) if (flag) REP(j, 10) if (f[i][j] == s[k]) {
                s[k] = f[i][j + 1];
                flag = false;
                break;
            }
        }
    }
    cout << s << endl;
    return 0;
}