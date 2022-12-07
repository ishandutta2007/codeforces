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

int ro = 0, co = 0;
bool rev;
int a, b, c, d, n;
char s[50][105];
int x[26];
int hor, ver;

int main() {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
    REP(i, n) scanf("%d", x + i);
    hor = a + c;
    ver = max(b, d);
    REP(i, ver) REP(j, hor) s[i][j] = '.';
    REP(i, ver) s[i][hor] = '\0';
    rev = a % 2 == 1;
    if (rev) ro = b - 1;
    REP(i, n) REP(j, x[i]) {
        s[ro][co] = 'a' + i;
        if (co < a) {
            if (rev) {
                if (ro == 0) rev = false, ++co;
                else --ro;
            } else {
                if (ro == b - 1) rev = true, ++co;
                else ++ro;
            }
        } else {
            if (rev) {
                if (ro == 0) rev = false, ++co;
                else --ro;
            } else {
                if (ro == d - 1) rev = true, ++co;
                else ++ro;
            }
        }
    }
    printf("YES\n");
    REP(i, ver) printf("%s\n", s[i]);
    return 0;
}