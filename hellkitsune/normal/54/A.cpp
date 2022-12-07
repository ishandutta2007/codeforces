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

int n, k, c;
bool d[366] = {};

int main() {
    scanf("%d%d%d", &n, &k, &c);
    REP(i, c) {
        int x;
        scanf("%d", &x);
        d[x] = true;
    }
    int pre = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i] || i - pre == k) {
            pre = i;
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}