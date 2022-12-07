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

LL x;
LL ans;

int main() {
    cin >> x;
    if (x == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (x < 0) x = -x;
    LL l = 1, r = 1e9, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (((mid * (mid + 1)) >> 1) < x)
            l = mid + 1;
        else
            r = mid;
    }
    LL dif = (l * (l + 1) >> 1) - x;
    while (dif & 1) {
        ++l;
        dif = (l * (l + 1) >> 1) - x;
    }
    cout << l << endl;
    return 0;
}