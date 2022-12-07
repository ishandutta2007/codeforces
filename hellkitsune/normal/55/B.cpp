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

int a[4];
char s[4], t[4];
vector<LL> pos;
LL ans = 1e18;

void go(vector<LL> &pos) {
    int sz = (int)pos.size();
    if (sz == 1) {
        ans = min(ans, pos[0]);
        return;
    }
    REP(i, sz) for (int j = i + 1; j < sz; ++j) {
        vector<LL> ppos;
        if (s[4 - sz] == '+') ppos.pb(pos[i] + pos[j]);
        else ppos.pb(pos[i] * pos[j]);
        REP(k, sz) if (k != i && k != j) {
            ppos.pb(pos[k]);
        }
        go(ppos);
    }
}

int main() {
    REP(i, 4) scanf("%d", a + i);
    REP(i, 3) {
        scanf("%s", t);
        s[i] = t[0];
    }
    REP(i, 4) pos.pb(a[i]);
    go(pos);
    cout << ans << endl;
    return 0;
}