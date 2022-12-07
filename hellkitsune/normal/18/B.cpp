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

LL n, d, m, l;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> d >> m >> l;
    LL pos = 0;
    LL le = -m, ri = -m + l;
    for (int i = 0; i < n; ++i) {
        le += m, ri += m;
        if (pos >= le + m) continue;
        pos += ((le + m - 1 - pos) / d) * d;
        if (pos > ri) {
            while (pos - d > ri) pos -= d;
            cout << pos << endl;
            return 0;
        }
        pos += d;
    }
    cout << pos << endl;
    return 0;
}