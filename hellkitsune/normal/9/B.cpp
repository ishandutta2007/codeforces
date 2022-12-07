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

int n;
double vb, vs;
double x[100];
double xu, yu;
double best, bestd;
int ans = 1;

const double EPS = 1e-9;

int main() {
    cin >> n >> vb >> vs;
    REP(i, n) cin >> x[i];
    cin >> xu >> yu;
    for (int i = 1; i < n; ++i) {
        double curd = sqrt((x[i] - xu) * (x[i] - xu) + yu * yu);
        double cur = x[i] / vb + curd / vs;
        if (ans == 1 || cur < best - EPS) {
            best = cur;
            bestd = curd;
            ans = i + 1;
        } else if ((cur - best) < EPS && curd < bestd) {
            best = cur;
            bestd = curd;
            ans = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}