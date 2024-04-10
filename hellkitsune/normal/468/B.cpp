#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <unordered_map>
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

int n, x, y;
int a[100000];
unordered_map<int, bool> ma, ex;
unordered_map<int, int> pos;
int ans[100000] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    REP(i, n) cin >> a[i], ex[a[i]] = ma[a[i]] = true, pos[a[i]] = i;
    REP(i, n) if (ma[a[i]]) {
        if (ma[x - a[i]]) {
            ma[a[i]] = ma[x - a[i]] = false;
            continue;
        }
        int cur = a[i];
        while (!ma[y - cur]) {
            if (!ex.count(y - cur)) {
                cout << "NO\n";
                return 0;
            }
            ans[pos[cur]] = ans[pos[y - cur]] = 1;
            ma[cur] = false;
            if (x - y + cur == y - cur) {
                cur = -1;
                break;
            } else
                cur = x - y + cur;
        }
        if (cur != -1) {
            ans[pos[cur]] = ans[pos[y - cur]] = 1;
            ma[cur] = ma[y - cur] = false;
        }
    }
    cout << "YES\n";
    REP(i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}