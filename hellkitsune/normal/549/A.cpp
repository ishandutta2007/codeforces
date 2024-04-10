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

char s[50][55];
int n, m;
int ans = 0;
bool f, a, c, e;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    REP(i, n - 1) REP(j, m - 1) {
        f = a = c = e = false;
        for (int y = i; y <= i + 1; ++y) for (int x = j; x <= j + 1; ++x) {
            if (s[y][x] == 'f') f = true;
            if (s[y][x] == 'a') a = true;
            if (s[y][x] == 'c') c = true;
            if (s[y][x] == 'e') e = true;
        }
        if (f && a && c && e) ++ans;
    }
    cout << ans << endl;
    return 0;
}