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

int n, b;
int a[2000];
int pre = -1;
int ans;

int main() {
    scanf("%d%d", &n, &b);
    ans = b;
    REP(i, n) scanf("%d", a + i);
    REP(i, n) for (int j = i + 1; j < n; ++j) if (a[j] > a[i]) {
        int cnt = b / a[i];
        ans = max(ans, b % a[i] + cnt * a[j]);
    }
    printf("%d\n", ans);
    return 0;
}