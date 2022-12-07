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

int n, k;
int a[51], cm[51];
vector<PII> ans;

void mergeCm(int x, int y) {
    if (cm[x] != cm[y]) {
        int z = cm[y];
        for (int i = 1; i <= n; ++i) if (cm[i] == z)
            cm[i] = cm[x];
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) a[i] = 2, cm[i] = i;
    REP(i, k) {
        int x, y;
        cin >> x >> y;
        --a[x];
        --a[y];
        mergeCm(x, y);
    }
    for (int i = 1; i <= n; ++i) if (a[i] < 0) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) while (a[i] > 0) {
        bool flag = true;
        for (int j = i + 1; j <= n; ++j) if (a[j] > 0 && cm[j] != cm[i]) {
            ans.pb(mp(i, j));
            --a[i];
            --a[j];
            mergeCm(i, j);
            flag = false;
            break;
        }
        if (!flag) continue;
        for (int j = i; j <= n; ++j) if (a[j] > 1 || (j != i && a[j] > 0)) {
            ans.pb(mp(i, j));
            --a[i];
            --a[j];
            flag = false;
            break;
        }
        if (flag) {
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int i = 2; i <= n; ++i) if (cm[i] != cm[1]) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl << ans.size() << endl;
    REP(i, ans.size())
        cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}