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

int a, b, n;

int main() {
    cin >> a >> b >> n;
    if (b == 0) {
        cout << "0\n";
        return 0;
    }
    if (a == 0) {
        cout << "No solution\n";
        return 0;
    }
    int mul = 1;
    if (a * b < 0) {
        if (n % 2 == 0) {
            cout << "No solution\n";
            return 0;
        }
        mul = -1;
    }
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b % a != 0) {
        cout << "No solution\n";
        return 0;
    }
    b /= a;
    for (int x = 1; ; ++x) {
        int t = 1;
        REP(i, n) t *= x;
        if (t > b) {
            cout << "No solution\n";
            return 0;
        }
        if (t == b) {
            cout << x * mul << '\n';
            return 0;
        }
    }
    return 0;
}