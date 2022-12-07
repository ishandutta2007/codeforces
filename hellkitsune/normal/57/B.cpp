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

LL ans;
int pos[100];
int a[100000], b[100000], c[100000];
int n, m, k;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, m) {
        scanf("%d%d%d", a + i, b + i, c + i);
    }
    REP(i, k) scanf("%d", pos + i);
    REP(i, m) REP(j, k) if (pos[j] >= a[i] && pos[j] <= b[i]) {
        ans += c[i] + pos[j] - a[i];
    }
    printf("%I64d\n", ans);
    return 0;
}