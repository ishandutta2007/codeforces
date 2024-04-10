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

char s[100005];
int n;

int main() {
    scanf("%s", s);
    n = strlen(s);
    bool was = false;
    for (int i = 0; i < n - 1; ) {
        if (!was && s[i] == 'A' && s[i + 1] == 'B') {
            was = true;
            i += 2;
            continue;
        }
        if (was && s[i] == 'B' && s[i + 1] == 'A') {
            printf("YES\n");
            return 0;
        }
        ++i;
    }

    was = false;
    for (int i = 0; i < n - 1; ) {
        if (!was && s[i] == 'B' && s[i + 1] == 'A') {
            was = true;
            i += 2;
            continue;
        }
        if (was && s[i] == 'A' && s[i + 1] == 'B') {
            printf("YES\n");
            return 0;
        }
        ++i;
    }

    printf("NO\n");
    return 0;
}