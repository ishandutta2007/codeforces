#include <cstdio>
#include <cmath>
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

int n, s;
pair<int, int> c[1005];

int main() {
    cin >> n >> s;
    REP(i, n) {
        int x, y, k;
        cin >> x >> y >> k;
        c[i].first = x * x + y * y;
        c[i].second = k;
    }
    sort(c, c + n);
    REP(i, n) {
        s += c[i].second;
        if (s >= 1000000) {
            cout << setprecision(12) << fixed << sqrt(c[i].first) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}