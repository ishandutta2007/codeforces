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

int h1, atk, def;
int h2, a2, d2;
int h, a, d;

int best = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> h1 >> atk >> def >> h2 >> a2 >> d2 >> h >> a >> d;
    atk -= d2;
    def -= a2;
    for (int i = 0; i == 0 || def + i <= 0; ++i) {
        for (int j = 0; j == 0 || atk + j <= h2; ++j) {
            int ATK = atk + j;
            if (ATK <= 0) continue;
            int DEF = def + i;
            int t = (h2 + ATK - 1) / ATK;
            int hp = max(h1, -DEF * t + 1);
            int cur = i * d + j * a + h * (hp - h1);
            best = min(best, cur);
        }
    }
    cout << best << '\n';
    return 0;
}