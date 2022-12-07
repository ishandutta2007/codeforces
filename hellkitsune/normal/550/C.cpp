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

char s[200];
int n;
int a[200];

int main() {
    scanf("%s", s);
    n = strlen(s);
    REP(i, n) a[i] = s[i] - '0';

    REP(i, n) if (a[i] == 8 || a[i] == 0) {
        printf("YES\n%d\n", a[i]);
        return 0;
    }
    REP(i, n) for (int j = i + 1; j < n; ++j) if ((a[i] * 10 + a[j]) % 8 == 0) {
        printf("YES\n%d\n", a[i] * 10 + a[j]);
        return 0;
    }

    int nz = 0;
    while (nz < n && a[nz] == 0) ++nz;
    REP(i, n) for (int j = i + 1; j < n; ++j) for (int k = j + 1; k < n; ++k) {
        int val = 100 * a[i] + 10 * a[j] + a[k];
        if (val % 8 == 0) {
            printf("YES\n%d\n", val);
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}