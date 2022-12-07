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

char s[1000005], t[1000005];

int main() {
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(t + 1);
    int l = 0;
    while (l < n && s[l + 1] == t[l + 1]) ++l;
    int r = n + 1;
    while (r > 1 && s[r] == t[r - 1]) --r;
    printf("%d\n", max(0, l - r + 2));
    for (int i = r; i <= l + 1; ++i) printf("%d ", i);
    printf("\n");
    return 0;
}