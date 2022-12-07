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

int w, h;
string s[200], t[100];

int main() {
    cin >> w >> h;
    REP(i, h) cin >> s[i];
    REP(i, w) t[i].resize(h);
    REP(i, h) REP(j, w)
        t[j][i] = s[i][j];
    swap(h, w);
    REP(i, h * 2) s[i].resize(w * 2);
    REP(i, h * 2) REP(j, w * 2) s[i][j] = t[i / 2][j / 2];
    REP(i, h * 2) cout << s[i] << endl;
    return 0;
}