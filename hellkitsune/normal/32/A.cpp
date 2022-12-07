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

int n, d;
int a[1000], ans = 0;

int main() {
    scanf("%d%d", &n, &d);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) REP(j, n) if (i != j && abs(a[i] - a[j]) <= d) {
        ++ans;
    }
    cout << ans << endl;
    return 0;
}