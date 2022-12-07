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
bool used[100001] = {};
vector<PII> ans;
bool p[100001];

int main() {
    cin >> n;
    REP(i, n + 1) p[i] = true;
    for (int i = 2; i * i <= n; ++i) if (p[i])
        for (int j = i * i; j <= n; j += i)
            p[j] = false;
    for (int i = 3; i <= (n >> 1); ++i) if (p[i]) {
        int prev = -1;
        for (int j = i; j <= n; j += i) if (j != (i << 1) && !used[j]) {
            if (prev == -1) prev = j;
            else {
                used[prev] = true;
                used[j] = true;
                ans.pb(mp(prev, j));
                prev = -1;
            }
        }
        if (prev != -1) {
            used[prev] = true;
            used[i << 1] = true;
            ans.pb(mp(prev, i << 1));
        }
    }
    int prev = -1;
    for (int i = 2; i <= n; i += 2) if (!used[i]) {
        if (prev == -1) prev = i;
        else {
            used[prev] = true;
            used[i] = true;
            ans.pb(mp(prev, i));
            prev = -1;
        }
    }
    printf("%d\n", (int)ans.size());
    REP(i, ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}