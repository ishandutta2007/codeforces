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

int n, r, avg;
LL tot;
LL ans = 0;
PII e[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> r >> avg;
    tot = (LL)avg * n;
    REP(i, n) cin >> e[i].second >> e[i].first;
    sort(e, e + n);
    REP(i, n) tot -= e[i].second;
    tot = max(tot, 0ll);
    REP(i, n) {
        LL dif = min(tot, (LL)r - e[i].second);
        tot -= dif;
        ans += dif * e[i].first;
    }
    cout << ans << '\n';
    return 0;
}