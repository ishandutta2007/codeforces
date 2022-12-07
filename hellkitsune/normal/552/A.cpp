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

int n;

int main() {
    scanf("%d", &n);
    LL ans = 0;
    REP(i, n) {
        int from, to, u, v;
        scanf("%d%d%d%d", &from, &u, &to, &v);
        ans += (abs(to - from) + 1) * (1 + abs(u - v));
    }
    cout << ans << endl;
    return 0;
}