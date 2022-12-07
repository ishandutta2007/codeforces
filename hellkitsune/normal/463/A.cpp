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

int n, s;
int ans = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    REP(i, n) {
        int x, y;
        cin >> x >> y;
        if (x < s || (x == s && y == 0)) {
            int cur = 100 - y;
            if (cur == 100) cur = 0;
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}