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

int c;
LL a, res, tmp;
char s[1000010], t[1000010];

int main() {
    scanf("%s%s%d", s, t, &c);
    a = 0;
    for (int i = 0; s[i]; ++i)
        a = (a * 10 + s[i] - '0') % c;
    int len = strlen(t);
    for (int i = len - 1; i >= 0; --i)
        if (t[i] == '0') t[i] = '9';
        else {
            --t[i];
            break;
        }
    res = a - 1;
    if (res < 0) res += c;
    for (int i = len - 1; i >= 0; --i) {
        REP(j, t[i] - '0')
            res = (res * a) % c;
        tmp = (a * a) % c;
        a = (tmp * tmp) % c;
        a = (a * a) % c;
        a = (a * tmp) % c;
    }
    if (res == 0) printf("%d\n", c);
    else printf("%d\n", (int)res);
    return 0;
}