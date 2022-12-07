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

int n;
int cnt[2][200001], mx[2], sz[2];
char s[5];
int pos;
set<int> se[2];

int main() {
    scanf("%d%d%d", sz + 0, sz + 1, &n);
    REP(i, 2) mx[i] = sz[i], cnt[i][mx[i]] = 1;
    REP(i, n) {
        scanf("%s%d", s, &pos);
        int ind, lo, hi;
        if (s[0] == 'V') ind = 0;
        else ind = 1;
        auto it = se[ind].lower_bound(pos);
        if (it == se[ind].end()) hi = sz[ind];
        else hi = *it;
        if (!se[ind].empty() && it != se[ind].begin()) {
            --it;
            lo = *it;
        } else {
            lo = 0;
        }
        se[ind].insert(pos);
        --cnt[ind][hi - lo];
        ++cnt[ind][pos - lo];
        ++cnt[ind][hi - pos];
        while (cnt[ind][mx[ind]] == 0) --mx[ind];
        printf("%I64d\n", (LL)mx[0] * mx[1]);
    }
    return 0;
}