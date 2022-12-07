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

vector<PII> pos, neg;
int n;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int x, a;
        scanf("%d%d", &x, &a);
        if (x > 0) pos.pb(mp(x, a));
        else neg.pb(mp(-x, a));
    }
    LL ans = 0;
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    int x, y;
    if (pos.size() > neg.size()) {
        y = (int)neg.size();
        x = y + 1;
    } else if (pos.size() < neg.size()) {
        x = (int)pos.size();
        y = x + 1;
    } else {
        x = y = (int)pos.size();
    }
    REP(i, x) ans += pos[i].second;
    REP(i, y) ans += neg[i].second;
    cout << ans << endl;
    return 0;
}