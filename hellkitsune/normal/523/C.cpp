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

const int INF = 1e9;

string s, t;
int n, m;
int lpos = INF, rpos = -1;

int main() {
    cin >> s >> t;
    n = (int)s.length();
    m = (int)t.length();
    int pos = 0;
    REP(i, m) if (t[i] == s[pos]) {
        if (++pos == n) {
            lpos = i;
            break;
        }
    }
    pos = n - 1;
    for (int i = m - 1; i >= 0; --i) if (t[i] == s[pos]) {
        if (--pos < 0) {
            rpos = i;
            break;
        }
    }
    if (rpos > lpos) cout << rpos - lpos << endl;
    else cout << 0 << endl;
    return 0;
}