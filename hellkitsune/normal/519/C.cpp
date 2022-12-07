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

int n, m, ans = 0;

int main() {
    cin >> n >> m;
    while (true) {
        if (n > m) {
            if (n < 2 || m < 1) break;
            n -= 2;
            --m;
            ++ans;
        } else {
            if (m < 2 || n < 1) break;
            m -= 2;
            --n;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}