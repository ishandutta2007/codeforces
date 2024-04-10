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

int xx[2], xy1[2], xy2[2], xc = 0;
int yy[2], yx1[2], yx2[2], yc = 0;

int main() {
    REP(i, 4) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((a == c && b == d) || (a != c && b != d)) {
            cout << "NO" << endl;
            return 0;
        }
        if (a == c) {
            if (xc == 2) {
                cout << "NO" << endl;
                return 0;
            }
            xx[xc] = a;
            if (b > d) swap(b, d);
            xy1[xc] = b;
            xy2[xc] = d;
            ++xc;
        } else {
            if (yc == 2) {
                cout << "NO" << endl;
                return 0;
            }
            yy[yc] = b;
            if (a > c) swap(a, c);
            yx1[yc] = a;
            yx2[yc] = c;
            ++yc;
        }
    }
    if (xy1[0] != xy1[1] || xy2[0] != xy2[1] || yx1[0] != yx1[1] || yx2[0] != yx2[1]) {
        cout << "NO" << endl;
        return 0;
    }
    if (xx[0] > xx[1]) swap(xx[0], xx[1]);
    if (yy[0] > yy[1]) swap(yy[0], yy[1]);
    if (xx[0] != yx1[0] || xx[1] != yx2[0] || yy[0] != xy1[0] || yy[1] != xy2[0]) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}