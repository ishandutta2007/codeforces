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
vector<int> a[200000];
int pos[200000] = {};
vector<int> ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        a[x].pb(i);
    }
    int cur = 0;
    REP(i, n) {
        while (cur >= 0 && pos[cur] == (int)a[cur].size())
            cur -= 3;
        if (cur < 0) {
            printf("Impossible\n");
            return 0;
        }
        ans.pb(a[cur][pos[cur]]);
        ++pos[cur];
        ++cur;
    }
    printf("Possible\n");
    REP(i, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}