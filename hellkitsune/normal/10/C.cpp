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
vector<int> d[10];
int pre[1000002];

int getD(int x) {
    int y = x;
    if (x < 10) return x;
    if (pre[x] != -1) return pre[x];
    int d = 0;
    while (x) {
        d += x % 10;
        x /= 10;
    }
    return pre[y] = getD(d);
}

int main() {
    cin >> n;
    REP(i, 1000001) pre[i] = -1;
    for (int i = 1; i <= n; ++i) d[getD(i)].pb(i);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        int di = getD(i);
        REP(j, 10) {
            int l = 0, r = d[j].size(), mid;
            while (l < r) {
                mid = (l + r) >> 1;
                if (i * (LL)d[j][mid] <= n)
                    l = mid + 1;
                else
                    r = mid;
            }
            int xy = getD(di * j);
            LL second = (int)d[xy].size() - 1;
            ans += l * second;
            ++second;
            ans += ((int)d[j].size() - l) * second;
        }
    }
    cout << ans << endl;
    return 0;
}