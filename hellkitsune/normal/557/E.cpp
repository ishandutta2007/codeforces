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

bool p[5000][5000] = {};
char s[5005];
int n, k;
int ord[5000];

inline bool cmp(const int &lhs, const int &rhs) {
    return strcmp(s + lhs, s + rhs) < 0;
}

void go(int from, int to, int len) {
    int ind;
    for (ind = from; ind <= to && s[ord[ind] + len] == 'a'; ++ind) {
        int x = ord[ind];
        if (p[x][x + len] && --k == 0) {
            s[x + len + 1] = '\0';
            printf("%s", s + x);
            exit(0);
        }
    }
    int newFrom = from;
    if (ord[newFrom] + len + 1 == n) ++newFrom;
    if (ind - 1 >= newFrom) go(newFrom, ind - 1, len + 1);

    newFrom = ind;
    for (; ind <= to; ++ind) {
        int x = ord[ind];
        if (p[x][x + len] && --k == 0) {
            s[x + len + 1] = '\0';
            printf("%s", s + x);
            exit(0);
        }
    }
    if (ord[newFrom] + len + 1 == n) ++newFrom;
    if (to >= newFrom) go(newFrom, to, len + 1);
}

int main() {
    scanf("%s%d", s, &k);
    n = strlen(s);
    REP(i, 4) REP(j, n - i) if (s[j] == s[j + i]) {
        int from = j, to = j + i;
        while (true) {
            p[from][to] = true;
            if (from < 2 || to > n - 3) break;
            from -= 2, to += 2;
            if (s[from] != s[to]) break;
        }
    }
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    go(0, n - 1, 0);
    return 0;
}