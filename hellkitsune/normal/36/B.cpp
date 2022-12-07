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

int n, k;
string s[3];
string t[750];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    REP(i, n) cin >> s[i];
    int m = 1;
    REP(i, k) m *= n;
    REP(i, m) t[i].resize(m);
    REP(i, m) REP(j, m) {
        t[i][j] = '.';
        int ii = i, jj = j;
        REP(z, k) {
            if (s[ii % n][jj % n] == '*') {
                t[i][j] = '*';
            }
            ii /= n;
            jj /= n;
        }
    }
    REP(i, m) printf("%s\n", t[i].c_str());
    return 0;
}