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

const int INF = 1e9 + 9;
int a[100000];
int n, k;
char s[20];
vector<int> v;

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) {
        scanf("%s", s);
        if (s[0] == '?') {
            a[i] = INF;
        } else {
            bool flag = false;
            char *c = s;
            if (*c == '-') flag = true, ++c;
            a[i] = 0;
            while (*c != '\0') {
                a[i] = 10 * a[i] + *c - '0';
                ++c;
            }
            if (flag) a[i] = -a[i];
        }
    }
    for (int st = 0; st < k; ++st) {
        v.clear();
        for (int pos = st; pos < n; pos += k) {
            v.pb(a[pos]);
        }
        int cnt = (int)v.size();
        REP(i, cnt - 1) if (v[i] != INF && v[i + 1] != INF) {
            if (v[i] >= v[i + 1]) {
                printf("Incorrect sequence\n");
                return 0;
            }
        }
        for (int beg = 0; beg < cnt; ) {
            if (v[beg] != INF) {
                ++beg;
                continue;
            }
            int end = beg + 1;
            while (end < cnt && v[end] == INF)
                ++end;
            int lo = (beg == 0) ? -2e9 : (v[beg - 1] + 1);
            int hi = (end == cnt) ? 2e9 : (v[end] - 1);
            hi -= end - beg - 1;
            if (lo > hi) {
                printf("Incorrect sequence\n");
                return 0;
            }
            int pref = -(end - beg) / 2;
            if (pref < lo) pref = lo;
            if (pref > hi) pref = hi;
            for (int i = beg; i < end; ++i) {
                a[st + i * k] = pref;
                ++pref;
            }
            beg = end;
        }
    }
    REP(i, n) printf("%d ", a[i]);
    printf("\n");
    return 0;
}