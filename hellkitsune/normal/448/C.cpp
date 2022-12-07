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

int n;
int a[5000];

const int INF = 1e9 + 9;

int go(int l, int r, int h) {
    int minh = INF;
    for (int i = l; i <= r; ++i)
        minh = min(minh, a[i]);
    vector<int> m;
    for (int i = l; i <= r; ++i) if (a[i] == minh)
        m.pb(i);
    int ms = m.size();
    int ret = 0;
    if (m[0] > l) ret += go(l, m[0] - 1, minh);
    if (m[ms - 1] < r) ret += go(m[ms - 1] + 1, r, minh);
    REP(i, ms - 1) if (m[i + 1] > m[i] + 1)
        ret += go(m[i] + 1, m[i + 1] - 1, minh);
    ret += minh - h;
    return min(ret, r - l + 1);
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    printf("%d\n", go(0, n - 1, 0));
    return 0;
}