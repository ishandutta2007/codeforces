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
string s[300];
int a[300];
bool used[300] = {}, vis[300];
int ans[300];

void go(int v) {
    vis[v] = true;
    REP(i, n) if (s[v][i] == '1' && !vis[i])
        go(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i], --a[i];
    REP(i, n) cin >> s[i];
    REP(i, n) {
        REP(j, n) vis[j] = false;
        go(i);
        int best = -1;
        REP(j, n) if (vis[j] && !used[j] && (best == -1 || a[j] < a[best]))
            best = j;
        ans[i] = a[best];
        used[best] = true;
    }
    REP(i, n) cout << ans[i] + 1 << ' ';
    cout << endl;
    return 0;
}