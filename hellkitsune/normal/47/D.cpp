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

vector<LL> cur, tot, tmp;
char s[40];
int n, m;
LL num;
int x;

void go(int pos) {
    if (pos == -1) {
        cur.pb(num);
        return;
    }
    if (num & (1ll << pos)) {
        if (pos >= x) {
            num ^= 1ll << pos;
            go(pos - 1);
            num ^= 1ll << pos;
        }
        if (x > 0) {
            --x;
            go(pos - 1);
            ++x;
        }
    } else {
        if (x > 0) {
            --x;
            go(pos - 1);
            ++x;
        }
        if (pos >= x) {
            num ^= 1ll << pos;
            go(pos - 1);
            num ^= 1ll << pos;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        scanf("%s%d", s, &x);
        num = 0;
        REP(i, n) if (s[i] == '1') {
            num |= 1ll << i;
        }
        go(n - 1);
        if (cur.empty()) {
            printf("0\n");
            return 0;
        }
        if (!i) {
            tot = cur;
            cur.clear();
        } else {
            int ci = 0, ti = 0;
            int cs = (int)cur.size(), ts = (int)tot.size();
            while (true) {
                while (ci < cs && cur[ci] < tot[ti]) ++ci;
                if (ci == cs) break;
                while (ti < ts && tot[ti] < cur[ci]) ++ti;
                while (ci < cs && ti < ts && cur[ci] == tot[ti]) {
                    tmp.pb(cur[ci]);
                    ++ci, ++ti;
                }
                if (ci == cs || ti == ts) break;
            }
            tot = tmp;
            tmp.clear();
            cur.clear();
            if (tot.empty()) {
                printf("0\n");
                return 0;
            }
        }
    }
    printf("%d\n", (int)tot.size());
    return 0;
}