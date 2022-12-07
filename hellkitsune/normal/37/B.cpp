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

int n, mx, reg, hp;
int po[1000], dmg[1000];
bool used[1000] = {};
vector<PII> ans;

int main() {
    scanf("%d%d%d", &n, &mx, &reg);
    REP(i, n) {
        scanf("%d%d", po + i, dmg + i);
    }
    hp = mx;
    int curT = 0;
    while (true) {
        hp = min(hp + reg, mx);
        if (hp <= 0) {
            printf("YES\n%d %d\n", curT, (int)ans.size());
            for (PII x : ans) {
                printf("%d %d\n", x.first, x.second);
            }
            return 0;
        }
        int best = -1;
        REP(i, n) if (!used[i] && 100 * hp <= po[i] * mx) {
            if (best == -1 || dmg[best] < dmg[i]) {
                best = i;
            }
        }
        if (best == -1 && reg >= 0) break;
        if (best != -1) {
            used[best] = true;
            ans.pb(mp(curT, best + 1));
            reg -= dmg[best];
        }
        ++curT;
    }
    printf("NO\n");
    return 0;
}