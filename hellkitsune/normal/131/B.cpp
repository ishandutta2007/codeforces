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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int _cnt[21] = {}, *cnt;

int main() {
    cnt = _cnt + 10;
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }
    LL ans = 0;
    for (int i = 1; i <= 10; ++i) ans += (LL)cnt[i] * cnt[-i];
    ans += ((LL)cnt[0] * (cnt[0] - 1)) >> 1;
    printf("%I64d\n", ans);
    return 0;
}