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

LL h, w;
LL best = -1, besth, bestw;

int main() {
    cin >> h >> w;
    for (LL hh = 1; hh <= h; hh <<= 1) {
        LL wmin = max(1ll, (4 * hh + 4) / 5);
        LL wmax = min(w, 5 * hh / 4);
        if (wmin <= wmax && (wmax * hh > best || (wmax * hh == best && hh > besth))) {
            best = wmax * hh;
            besth = hh;
            bestw = wmax;
        }
    }
    for (LL ww = 1; ww <= w; ww <<= 1) {
        LL hmin = max(1ll, (4 * ww + 4) / 5);
        LL hmax = min(h, 5 * ww / 4);
        if (hmin <= hmax && (hmax * ww > best || (hmax * ww == best && hmax > besth))) {
            best = hmax * ww;
            besth = hmax;
            bestw = ww;
        }
    }
    assert(best != -1);
    cout << besth << ' ' << bestw << endl;
    return 0;
}