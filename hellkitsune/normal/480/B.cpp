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

int n, l, x, y;
set<int> se;
int d[100000];
bool xx = false, yy = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> l >> x >> y;
    REP(i, n) {
        cin >> d[i];
        se.insert(d[i]);
    }
    REP(i, n) {
        if (se.count(d[i] + x))
            xx = true;
        if (se.count(d[i] + y))
            yy = true;
    }
    if (xx && yy) {
        cout << "0\n";
        return 0;
    }
    if (xx) {
        cout << "1\n" << y << '\n';
    } else if (yy) {
        cout << "1\n" << x << '\n';
    } else {
        REP(i, n) {
            int t = d[i] - x;
            if (t > 0 && (se.count(t + y) || se.count(t - y))) {
                cout << "1\n" << t << '\n';
                return 0;
            }
            t = d[i] + x;
            if (t < l && (se.count(t + y) || se.count(t - y))) {
                cout << "1\n" << t << '\n';
                return 0;
            }
            t = d[i] - y;
            if (t > 0 && (se.count(t + x) || se.count(t - x))) {
                cout << "1\n" << t << '\n';
                return 0;
            }
            t = d[i] + y;
            if (t < l && (se.count(t + x) || se.count(t - x))) {
                cout << "1\n" << t << '\n';
                return 0;
            }
        }
        cout << "2\n" << x << ' ' << y << '\n';
    }
    return 0;
}