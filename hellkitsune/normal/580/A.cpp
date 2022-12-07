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

int n, a[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    int ans = 1, cur = 1;
    for (int i = 1; i < n; ++i) if (a[i] >= a[i - 1]) {
        ++cur;
        ans = max(ans, cur);
    } else {
        cur = 1;
    }
    printf("%d\n", ans);
    return 0;
}