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

int a1, b1, c1, a2, b2, c2;

int main() {
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    if ((!a1 && !b1 && c1) || (!a2 && !b2 && c2)) {
        cout << 0 << endl;
        return 0;
    }
    if ((!a1 && !b1 && !c1) || (!a2 && !b2 && !c2)) {
        cout << -1 << endl;
        return 0;
    }
    int det = (a1 * b2 - a2 * b1);
    if (det == 0) {
        if ((a1 * a2 < 0) || (b1 * b2 < 0))
            c1 = -c1;
        if (c1 == c2) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }
    cout << 1 << endl;
    return 0;
}