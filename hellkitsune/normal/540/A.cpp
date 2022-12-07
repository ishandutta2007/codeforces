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
char s[1005], t[1005];

int main() {
    scanf("%d%s%s", &n, s, t);
    int ans = 0;
    REP(i, n) {
        int a = s[i] - '0';
        int b = t[i] - '0';
        ans += min(abs(b - a), 10 - abs(b - a));
    }
    printf("%d\n", ans);
    return 0;
}