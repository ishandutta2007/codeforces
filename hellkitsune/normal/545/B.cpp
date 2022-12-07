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

char s[100005], t[100005];
int n, bal = 0;
char p[100005];

int main() {
    scanf("%s%s", s, t);
    n = strlen(s);
    REP(i, n) {
        if (s[i] == t[i]) {
            p[i] = '0';
        } else {
            if (bal > 0) {
                --bal;
                p[i] = s[i];
            } else {
                ++bal;
                p[i] = t[i];
            }
        }
    }
    if (bal != 0) {
        printf("impossible\n");
    } else {
        printf("%s\n", p);
    }
    return 0;
}