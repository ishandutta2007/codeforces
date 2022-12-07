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

int gcd2(int a, int b, LL &x, LL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL xx, yy;
    int g = gcd2(b, a % b, xx, yy);
    x = yy;
    y = xx - (a / b) * yy;
    return g;
}

int main() {
    int a, b, c;
    LL x, y;
    cin >> a >> b >> c;
    int g = gcd2(a, b, x, y); //ax + by = g
    if (c % g != 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << x * (-c / g) << ' ' << y * (-c / g) << endl;
    return 0;
}