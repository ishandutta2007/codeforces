#include <cstdio>
#include <cmath>
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

struct st {
    int x, y, id;
    bool operator< (const st &rhs) const {
        return x < rhs.x;
    }
};

int n, x, y, k = 1;
st a[5001];
int d[5001], prev[5001], ans[5001], ansc = 0;

int main() {
    cin >> n >> x >> y;
    REP(i, n) {
        cin >> a[k].x >> a[k].y;
        a[k].id = i + 1;
        if (a[k].x > x && a[k].y > y)
            ++k;
    }
    a[0].x = 0; a[0].y = 0; a[0].id = 0;
    sort(a, a + k);
    d[0] = 0;
    for (int i = 1; i < k; ++i) {
        d[i] = 1;
        prev[i] = 0;
        for (int j = 1; j < i; ++j)
        if (a[j].x < a[i].x && a[j].y < a[i].y && d[j] + 1 > d[i]) {
            d[i] = d[j] + 1;
            prev[i] = j;
        }
    }
    int mx = 0;
    for (int i = 1; i < k; ++i)
        if (d[i] > d[mx])
            mx = i;
    while (mx != 0) {
        ans[ansc++] = a[mx].id;
        mx = prev[mx];
    }
    cout << ansc << endl;
    for (int i = ansc - 1; i >= 0; --i)
        cout << ans[i] << ' ';
    if (ansc) cout << endl;
    return 0;
}