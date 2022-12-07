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

string s[50];
int n, m;
int minx = 100, miny = 100, maxx = -100, maxy = -100;

int main() {
    cin >> n >> m;
    REP(i, n) cin >> s[i];
    REP(i, n) REP(j, m) if (s[i][j] == '*') {
        minx = min(minx, i);
        maxx = max(maxx, i);
        miny = min(miny, j);
        maxy = max(maxy, j);
    }
    for (int i = minx; i <= maxx; ++i)
        cout << s[i].substr(miny, maxy - miny + 1) << endl;
    return 0;
}