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
int a[3000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    sort(a, a + n);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        while (a[i] <= a[i - 1]) {
            ++a[i];
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}