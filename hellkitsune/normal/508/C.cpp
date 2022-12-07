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

int n, t, r;
bool used[1005] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> t >> r;
    if (t < r) {
        cout << -1 << endl;
        return 0;
    }
    REP(i, n) {
        int x;
        cin >> x;
        x += 500;
        int cnt = 0;
        for (int j = x - t; j < x; ++j) if (used[j])
            ++cnt;
        for (int j = x - 1; cnt < r; --j) if (!used[j]) {
            ++cnt;
            used[j] = true;
        }
    }
    int ans = 0;
    REP(i, 1000) if (used[i])
        ++ans;
    cout << ans << endl;
    return 0;
}