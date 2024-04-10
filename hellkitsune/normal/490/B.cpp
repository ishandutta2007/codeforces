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
int a[200000] = {};
int nx[1000001] = {}, pre[1000001] = {};
set<int> ys;
int xs[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        int x, y;
        cin >> x >> y;
        nx[x] = y;
        pre[y] = x;
        ys.insert(y);
        xs[i] = x;
    }
    int cur = 0;
    for (int i = 1; i < n; i += 2) {
        cur = nx[cur];
        a[i] = cur;
    }
    REP(i, n) if (xs[i] != 0 && !ys.count(xs[i])) {
        cur = xs[i];
        break;
    }
    for (int i = 0; i < n; i += 2) {
        a[i] = cur;
        cur = nx[cur];
    }
    REP(i, n) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}