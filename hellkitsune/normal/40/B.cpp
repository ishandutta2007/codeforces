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
typedef long long LL;
typedef pair<int, int> PII;

int n, m, x;
int cur, ans = 0;

int main() {
    cin >> n >> m >> x;
    while (n > 0 && m > 0) {
        cur = (n - n % 2) * (m - m % 2) / 2;
        if ((n & 1) && (m & 1)) {
            cur += n / 2 + m / 2 + 1;
        } else if (n & 1) {
            cur += m / 2;
        } else if (m & 1) {
            cur += n / 2;
        }
        n -= 2, m -= 2;
        if (--x == 0) {
            ans = cur;
        }
        if (x == -1) {
            ans -= cur;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}