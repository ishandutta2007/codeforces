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

int x[3], y[3];

bool check(int a, int b, int c) {
    int x1 = x[b] - x[a];
    int y1 = y[b] - y[a];
    int x2 = x[c] - x[a];
    int y2 = y[c] - y[a];
    return x1 * x2 + y1 * y2 == 0 && x1 * y2 - x2 * y1 != 0;
}

bool isIt() {
    return check(0, 1, 2) || check(1, 0, 2) || check(2, 0, 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    REP(i, 3) cin >> x[i] >> y[i];
    if (isIt()) {
        cout << "RIGHT\n";
        return 0;
    }
    for (int i = -1; i <= 1; i += 2) {
        x[0] += i; if (isIt()) {cout << "ALMOST\n"; return 0;} x[0] -= i;
        x[1] += i; if (isIt()) {cout << "ALMOST\n"; return 0;} x[1] -= i;
        x[2] += i; if (isIt()) {cout << "ALMOST\n"; return 0;} x[2] -= i;
        y[0] += i; if (isIt()) {cout << "ALMOST\n"; return 0;} y[0] -= i;
        y[1] += i; if (isIt()) {cout << "ALMOST\n"; return 0;} y[1] -= i;
        y[2] += i; if (isIt()) {cout << "ALMOST\n"; return 0;} y[2] -= i;
    }
    cout << "NEITHER\n";
    return 0;
}