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

double l, d, v, g, r;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> l >> d >> v >> g >> r;
    double t = d / v;
    double rem = t - round(t / (g + r)) * (g + r);
    while (rem < 0) rem += g + r;
    while (rem > g + r) rem -= g + r;
    if (rem > g - 1e-12)
        t = t - rem + g + r;
    t += (l - d) / v;
    cout << setprecision(12) << t << endl;
    return 0;
}