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

double d[1000] = {}, k[1000], c[1000];
int n, m, y, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> y >> x;
    if (m == 1) {
        cout << (n - y) * 2 << endl;
        return 0;
    }
    double tmp = n - y;
    while (y++ < n) {
        k[0] = 0.5, c[0] = d[0] / 2.0 + 1;
        for (int i = 1; i < m - 1; ++i) {
            double divis = 1.0 - k[i - 1] / 3.0;
            k[i] = 1.0 / (3.0 * divis);
            c[i] = (d[i] / 3.0 + 1 + c[i - 1] / 3.0) / divis;
        }
        double divis = 1.0 - k[m - 2] / 2.0;
        c[m - 1] = (d[m - 1] / 2.0 + 1 + c[m - 2] / 2.0) / divis;
        for (int i = m - 2; i >= 0; --i)
            c[i] += k[i] * c[i + 1];
        REP(i, m) d[i] = c[i];
    }
    cout << setprecision(15) << fixed << d[x - 1] + tmp << endl;
    return 0;
}