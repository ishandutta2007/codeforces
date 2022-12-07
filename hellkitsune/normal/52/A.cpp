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

int n, cnt[3] = {};

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x), --x;
        ++cnt[x];
    }
    int tot = 0;
    REP(i, 3) tot += cnt[i];
    int ans = tot;
    REP(i, 3) ans = min(ans, tot - cnt[i]);
    printf("%d\n", ans);
    return 0;
}