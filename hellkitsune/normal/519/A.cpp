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

int val[256] = {};

int main() {
    val['Q'] = 9;
    val['R'] = 5;
    val['B'] = 3;
    val['N'] = 3;
    val['P'] = 1;
    val['q'] = -9;
    val['r'] = -5;
    val['b'] = -3;
    val['n'] = -3;
    val['p'] = -1;
    int tot = 0;
    REP(i, 8) {
        string s;
        cin >> s;
        REP(j, 8) {
            tot += val[(int)s[j]];
        }
    }
    if (tot > 0) cout << "White\n";
    else if (tot < 0) cout << "Black\n";
    else cout << "Draw\n";
    return 0;
}