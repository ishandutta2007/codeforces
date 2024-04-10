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

int n, m;
char s[100005];
LL ans = 0;

int main() {
    scanf("%d%d%s", &n, &m, s);
    int k = 1;
    REP(i, n - 1) if (s[i] != s[i + 1]) {
        ++k;
    }
    ans = (LL)n * (m - 1) * k;
    for (int beg = 0; beg < n - 1; ) if (s[beg] != s[beg + 1]) {
        int end = beg + 2;
        while (end < n && s[end] == s[end - 2]) ++end;
        int sz = end - beg;
        ans -= (LL)sz * (sz - 1) / 2;
        beg = end - 1;
    } else {
        ++beg;
    }
    cout << ans << endl;
    return 0;
}