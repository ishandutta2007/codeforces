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
int a[100000];
vector<int> pos[100000];
int MX = 100000;
int ans[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i), --a[i];
    REP(i, n) pos[a[i]].pb(i);
    REP(i, MX - 1) if (pos[i].size() < pos[i + 1].size()) {
        printf("-1\n");
        return 0;
    }
    REP(i, MX) {
        REP(j, pos[i].size()) {
            ans[pos[i][j]] = j + 1;
        }
    }
    printf("%d\n", (int)pos[0].size());
    REP(i, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}