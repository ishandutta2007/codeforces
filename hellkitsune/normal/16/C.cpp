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

LL a, b, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> x >> y;
    LL g = __gcd(x, y);
    x /= g;
    y /= g;
    a -= a % x;
    b -= b % y;
    if (!a || !b) {
        cout << "0 0\n";
        return 0;
    }
    if ((a / x) * y <= b) {
        b = (a / x) * y;
    } else {
        a = (b / y) * x;
    }
    cout << a << ' ' << b << '\n';
    return 0;
}