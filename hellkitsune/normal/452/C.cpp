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

int n, m;
double ans = 0, tot;
double c[1002] = {}, c2[1002];

int main() {
    cin >> n >> m;
    tot = n * m;
    c[0] = 1;
    REP(i, n) {
        REP(j, m + 1) c2[j] = 0;
        REP(j, m + 1) {
            c2[j + 1] += c[j] * (m - j) / (tot - i);
            c2[j] += c[j] * (tot - i + j - m) / (tot - i);
        }
        REP(j, m + 1) c[j] = c2[j];
    }
    for (int i = 1; i <= min(n, m); ++i) {
        ans += c[i] * i * i;
    }
    ans /= n;
    cout << setprecision(15) << fixed << ans << endl;
    return 0;
}