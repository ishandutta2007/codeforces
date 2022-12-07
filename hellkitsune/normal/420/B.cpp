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

int n, m;
bool lead[100001], curin[100001];
int cnt = 0, ans, lastcnt = 0;
char qs[100000];
int qn[100000];
int last = -1, first = 0;
bool firstf = true;

int main() {
    char q[10];
    scanf("%d%d", &n, &m);
    REP(i, n + 1) lead[i] = true;
    REP(i, n + 1) curin[i] = false;
    REP(i, m) {
        scanf("%s%d", q, qn + i);
        qs[i] = q[0];
        if (qs[i] == '-' && qn[i] == qn[0] && cnt > 1)
            firstf = false;
        if (qs[i] == '-' && first == 0 && qn[i] == qn[0])
            first = i;
        if (qs[i] == '+' && qn[i] == qn[0] && first == i - 1)
            first = 0;
        lead[qn[i]] = false;
        if (qs[i] == '+') {
            ++cnt;
            curin[qn[i]] = true;
        } else {
            if (!curin[qn[i]]) {
                last = i;
                lastcnt = cnt;
            } else {
                curin[qn[i]] = false;
                --cnt;
            }
        }
    }

    if (last == -1 && firstf && (first == 0 || first == m - 1) && qs[0] == '+')
        lead[qn[0]] = true;
    if (last != - 1 && lastcnt == 0)
    if (last == m - 1 || qn[last + 1] == qn[last]) {
            lead[qn[last]] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (lead[i])
        ++ans;
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) if (lead[i])
        printf("%d ", i);
    printf("\n");
    return 0;
}