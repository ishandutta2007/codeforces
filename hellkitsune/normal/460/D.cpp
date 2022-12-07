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

LL l, r;
int k;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> l >> r >> k;
    if (k >= 4) {
        LL t = l;
        while (t % 2 != 0) ++t;
        if (r - t >= 3) {
            cout << "0\n4\n" << t << ' ' << t + 1 << ' ' << t + 2 << ' ' << t + 3 << '\n';
            return 0;
        }
    }
    LL t = 1;
    while (t < l) t = (t << 1) | 1;
    if (t < r && k >= 3) {
        LL tmp = t + 1;
        tmp |= tmp >> 1;
        LL t2 = t ^ tmp;
        LL t3 = t2 + 1;
        if (t3 <= r) {
            cout << "0\n3\n" << t << ' ' << t2 << ' ' << t3 << '\n';
            return 0;
        }
    }
    if (k >= 3 && l == 1) {
        cout << "0\n3\n1 2 3\n";
        return 0;
    }
    if (k >= 2 && r > l + l % 2) {
        l += l % 2;
        cout << "1\n2\n" << l << ' ' << l + 1 << '\n';
        return 0;
    }
    if (l == 1) {
        cout << "1\n1\n1\n";
        return 0;
    }
    if (k >= 2 && r > l && (l ^ r) < l) {
        cout << (l ^ r) << "\n2\n" << l << ' ' << r << '\n';
        return 0;
    }
    cout << l << "\n1\n" << l << '\n';
    return 0;
}