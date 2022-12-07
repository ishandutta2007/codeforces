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

char s[1000007];
int n, a, b;
int d[1000007] = {};

int main() {
    scanf("%s%d%d", s, &a, &b);
    if (s[0] == '0') {
        printf("NO\n");
        return 0;
    }
    n = strlen(s);
    int cur = 0;
    REP(i, n) {
        cur = (10 * cur + s[i] - '0') % a;
        if (cur == 0) ++d[i];
    }
    cur = 0;
    int mul = 1;
    for (int i = n - 1; i >= 1; --i) {
        cur = (cur + mul * (s[i] - '0')) % b;
        mul = (10 * mul) % b;
        if (cur == 0 && s[i] != '0') ++d[i - 1];
    }
    REP(i, n - 1) if (d[i] == 2) {
        printf("YES\n");
        char tmp = s[i + 1];
        s[i + 1] = '\0';
        printf("%s\n", s);
        s[i + 1] = tmp;
        printf("%s\n", s + i + 1);
        return 0;
    }
    printf("NO\n");
    return 0;
}