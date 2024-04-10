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

LL n, a, b;
LL s = 4e18, a1, b1;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    n *= 6;
    REP(i, 100000) {
        LL B = b + i;
        LL A = max(a, (n + B - 1) / B);
        if (A * B < s) {
            s = A * B;
            a1 = A;
            b1 = B;
        }
    }
    REP(i, 100000) {
        LL A = a + i;
        LL B = max(b, (n + A - 1) / A);
        if (A * B < s) {
            s = A * B;
            a1 = A;
            b1 = B;
        }
    }
    cout << s << endl << a1 << ' ' << b1 << endl;
    return 0;
}