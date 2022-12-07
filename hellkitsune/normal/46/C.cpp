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
int cntH = 0, ans = 12345;
char s[2005];

int main() {
    scanf("%d%s", &n, s);
    REP(i, n) if (s[i] == 'H') {
        ++cntH;
    }
    REP(i, n) s[n + i] = s[i];
    REP(st, n) {
        int cur = 0;
        REP(i, cntH) if (s[st + i] == 'T') {
            ++cur;
        }
        ans = min(ans, cur);
    }
    printf("%d\n", ans);
    return 0;
}