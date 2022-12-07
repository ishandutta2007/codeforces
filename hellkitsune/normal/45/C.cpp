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
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[200005];
int a[200005];
int nx[200005], pr[200005];
vector<PII> ans;
bool used[200005] = {};

priority_queue<PII, vector<PII>, greater<PII> > q;

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    REP(i, n) scanf("%d", a + i);
    REP(i, n - 1) nx[i] = i + 1;
    nx[n - 1] = -1;
    REP(i, n - 1) pr[i + 1] = i;
    pr[0] = -1;
    REP(i, n - 1) if (s[i] != s[i + 1]) {
        q.push(mp(abs(a[i] - a[i + 1]), i));
    }
    while (!q.empty()) {
        int v = q.top().second;
        int cc = q.top().first;
        q.pop();
        if (used[v] || nx[v] == -1 || used[nx[v]] || cc != abs(a[v] - a[nx[v]])) {
            continue;
        }
        used[v] = true;
        used[nx[v]] = true;
        ans.pb(mp(v + 1, nx[v] + 1));
        int pre = pr[v], nex = nx[nx[v]];
        if (pre != -1) {
            nx[pre] = nex;
        }
        if (nex != -1) {
            pr[nex] = pre;
        }
        if (pre != -1 && nex != -1 && s[pre] != s[nex]) {
            q.push(mp(abs(a[pre] - a[nex]), pre));
        }
    }
    printf("%d\n", (int)ans.size());
    for (PII x : ans) printf("%d %d\n", x.first, x.second);
    return 0;
}