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
bool g[100];
vector<int> ans;

int main() {
    scanf("%d", &n);
    REP(i, n) g[i] = true;
    REP(i, n) REP(j, n) {
        int x;
        scanf("%d", &x);
        if (x == 1) g[i] = false;
        else if (x == 2) g[j] = false;
        else if (x == 3) g[i] = g[j] = false;
    }
    REP(i, n) if (g[i]) ans.pb(i);
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x + 1);
    printf("\n");
    return 0;
}