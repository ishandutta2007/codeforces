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

int cnt[26] = {}, a[26] = {}, b[26] = {};
char sa[100005], sb[100005];
int n;
int ac = 0, bc = 0;

void go(char *s, int *arr) {
    scanf("%s", s);
    n = strlen(s);
    REP(i, n) ++arr[s[i] - 'a'];
}

int main() {
    go(sa, cnt);
    go(sa, a);
    go(sb, b);
    bool flag = true;
    while (flag) {
        REP(i, 26) if (a[i] > cnt[i]) {
            flag = false;
            break;
        }
        if (flag) {
            REP(i, 26) cnt[i] -= a[i];
            ++ac;
        }
    }
    flag = true;
    while (flag) {
        REP(i, 26) if (b[i] > cnt[i]) {
            flag = false;
            break;
        }
        if (flag) {
            REP(i, 26) cnt[i] -= b[i];
            ++bc;
        }
    }
    flag = true;
    while (flag) {
        if (ac == 0) flag = false;
        if (flag) REP(i, 26) if (cnt[i] + a[i] < b[i]) {
            flag = false;
            break;
        }
        if (flag) {
            REP(i, 26) cnt[i] += a[i];
            --ac;
            bool flag2 = true;
            while (flag2) {
                REP(i, 26) if (b[i] > cnt[i]) {
                    flag2 = false;
                    break;
                }
                if (flag2) {
                    REP(i, 26) cnt[i] -= b[i];
                    ++bc;
                }
            }
        }
    }
    REP(i, ac) printf("%s", sa);
    REP(i, bc) printf("%s", sb);
    REP(i, 26) REP(j, cnt[i]) printf("%c", char(i + 'a'));
    printf("\n");
    return 0;
}