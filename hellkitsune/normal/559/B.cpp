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

char s[200005], t[200005];
int n;

bool solve(int from, int ffrom, int len) {
    if (len & 1) {
        REP(i, len) if (s[from + i] != t[ffrom + i]) {
            return false;
        }
        return true;
    } else {
        int nlen = len >> 1;
        return (solve(from, ffrom, nlen) && solve(from + nlen, ffrom + nlen, nlen)) ||
                (solve(from + nlen, ffrom, nlen) && solve(from, ffrom + nlen, nlen));
    }
}

int main() {
    scanf("%s%s", s, t);
    n = strlen(s);
    if (solve(0, 0, n)) printf("YES\n");
    else printf("NO\n");
    return 0;
}