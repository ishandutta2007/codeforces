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

int n, m;
int q[1000];
int c[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> q[i];
    cin >> m;
    REP(i, n) c[i] = -1;
    REP(i, m) {
        int x, y, z;
        cin >> x >> y >> z, --y;
        if (c[y] == -1) c[y] = z;
        else c[y] = min(c[y], z);
    }
    int cnt = 0;
    LL tot = 0;
    REP(i, n) if (c[i] == -1) ++cnt;
    else tot += c[i];
    if (cnt > 1) cout << "-1\n";
    else cout << tot << endl;
    return 0;
}