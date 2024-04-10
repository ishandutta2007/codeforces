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

string s1, s2;
int a[150000] = {}, b[150000] = {}, ac = 0, bc = 0;
const double z = (sqrt(5.0) + 1.0) * 0.5;

double x = 0, y = 0;
const double EPS = 1e-3;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s1 >> s2;
    ac = s1.length();
    bc = s2.length();
    REP(i, ac) a[i] = s1[ac - 1 - i] - '0';
    REP(i, bc) b[i] = s2[bc - 1 - i] - '0';
    int st = max(max(ac, bc) - 1, 1);
    x = a[st] - b[st];
    for (int i = st; i > 0; --i) {
        y += a[i - 1] - b[i - 1];
        if (i == 1) {
            if (abs(x) < EPS && abs(y) < EPS) cout << "=\n";
            else if (x * z + y > 0) cout << ">\n";
            else cout << "<\n";
            return 0;
        }
        if (x * z + y > 10) {
            cout << ">\n";
            return 0;
        }
        if (x * z + y < -10) {
            cout << "<\n";
            return 0;
        }
        LL tmp = x;
        x += y;
        y = tmp;
    }
    return 0;
}