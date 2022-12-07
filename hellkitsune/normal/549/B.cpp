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
char s[105];
int a[100][100];
int b[100];
bool used[100] = {};
int sum[100] = {};

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%s", s);
        REP(j, n) a[i][j] = s[j] - '0';
    }
    REP(i, n) scanf("%d", b + i);
    bool flag = true;
    while (flag) {
        flag = false;
        REP(i, n) if (sum[i] == b[i]) {
            assert(!used[i]);
            used[i] = flag = true;
            REP(j, n) sum[j] += a[i][j];
        }
    }
    vector<int> ans;
    REP(i, n) if (used[i]) ans.pb(i + 1);
    printf("%d\n", (int)ans.size());
    REP(i, ans.size()) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}