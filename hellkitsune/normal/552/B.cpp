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

LL ans, n;

int main() {
    cin >> n;
    ans = 0;
    LL x = 9, cnt = 1, cur = 1;
    while (true) {
        if (n <= x) {
            ans += (n - cur + 1) * cnt;
            break;
        }
        ans += (x - cur + 1) * cnt;
        cur = x + 1;
        x *= 10;
        x += 9;
        ++cnt;
    }
    cout << ans << endl;
    return 0;
}