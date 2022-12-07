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

int a[4];
int ans = 0;

int solve(int x, int y, int z) {
    if (a[z] > a[x] + a[y]) return 0;
    if (a[z] == a[x] + a[y]) return 1;
    return 2;
}

int main() {
    REP(i, 4) cin >> a[i];
    sort(a, a + 4);
    ans = max(ans, solve(0, 1, 2));
    ans = max(ans, solve(0, 1, 3));
    ans = max(ans, solve(0, 2, 3));
    ans = max(ans, solve(1, 2, 3));
    if (ans == 0) cout << "IMPOSSIBLE" << endl;
    else if (ans == 1) cout << "SEGMENT" << endl;
    else cout << "TRIANGLE" << endl;
    return 0;
}