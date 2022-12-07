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

int p[4];
int a, b;
int ord[77][4];
int c = 0;

int main() {
    REP(i, 4) scanf("%d", p + i);
    scanf("%d%d", &a, &b);
    REP(i, 4) REP(j, 4) REP(k, 4) REP(t, 4) {
        if (i == j || i == k || i == t || j == k || j == t || k == t) continue;
        ord[c][0] = i;
        ord[c][1] = j;
        ord[c][2] = k;
        ord[c][3] = t;
        ++c;
    }
    assert(c == 24);
    int ans = 0;
    for (int x = a; x <= b; ++x) {
        int cnt = 0;
        REP(c, 24) {
            int i = ord[c][0];
            int j = ord[c][1];
            int k = ord[c][2];
            int t = ord[c][3];
            if (x % p[i] % p[j] % p[k] % p[t] == x) {
                ++cnt;
            }
        }
        if (cnt >= 7) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}