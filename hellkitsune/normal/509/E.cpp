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

char s[500005];
int a[500005], n;

inline int ctoi(char c) {
    if (c == 'I' || c == 'E' || c == 'A' || c == 'O' || c == 'U' || c == 'Y')
        return 1;
    return 0;
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    REP(i, n) a[i] = ctoi(s[i]);
    int cnt = 0;
    REP(i, n) cnt += a[i];
    LL sum = 0;
    int d = 0;
    double ans = cnt;
    for (int i = 2; i <= n; ++i) {
        d += a[i - 2] + a[n + 1 - i];
        sum += d;
        ans += cnt - (double)sum / i;
    }
    printf("%.15f\n", ans);
    return 0;
}