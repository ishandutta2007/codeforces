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

int n, p;
char s[1005];

int main() {
    scanf("%d%d%s", &n, &p, s);
    if (p == 1) {
        printf("NO\n");
        return 0;
    }
    if (p == 2) {
        if (s[0] == 'b') printf("NO\n");
        else if (n == 1) printf("b\n");
        else printf("ba\n");
        return 0;
    }
    int i;
    for (i = n - 1; i >= 0; --i) {
        ++s[i];
        while ((i > 0 && s[i] == s[i - 1]) || (i > 1 && s[i] == s[i - 2]))
            ++s[i];
        if (s[i] - 'a' < p) break;
    }
    if (i == -1) {
        printf("NO\n");
        return 0;
    }
    for (int j = i + 1; j < n; ++j) {
        s[j] = 'a';
        while ((j > 0 && s[j] == s[j - 1]) || (j > 1 && s[j] == s[j - 2]))
            ++s[j];
    }
    printf("%s", s);
    return 0;
}