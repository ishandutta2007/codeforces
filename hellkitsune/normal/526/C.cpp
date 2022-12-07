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

int c, hap[2], w[2];

int main() {
    cin >> c;
    REP(i, 2) cin >> hap[i];
    REP(i, 2) cin >> w[i];
    if ((hap[0] > hap[1] && w[0] > w[1]) || (hap[0] < hap[1] && w[0] < w[1])) {
        if (hap[0] * (LL)w[1] < hap[1] * (LL)w[0])
            swap(hap[0], hap[1]), swap(w[0], w[1]);
        int cnt = c / w[0];
        LL ans = (LL)cnt * hap[0];
        int rem = c % w[0];
        ans += (rem / w[1]) * (LL)hap[1];
        rem %= w[1];
        int times = 0;
        LL best = ans;
        while (cnt > 0) {
            if (++times >= 500000) break;
            --cnt;
            rem += w[0];
            ans -= hap[0];
            if (rem < w[1]) {
                int tmp = (w[1] - rem + w[0] - 1) / w[0];
                if (tmp > cnt) break;
                cnt -= tmp;
                ans -= (LL)tmp * hap[0];
                rem += tmp * (LL)w[0];
            }
            ans += (rem / w[1]) * (LL)hap[1];
            rem %= w[1];
            best = max(best, ans);
        }
        cout << best << endl;
    } else if (hap[0] > hap[1] || w[0] < w[1] || (hap[0] == hap[1] && w[0] == w[1])) {
        int cnt = c / w[0];
        cout << (LL)cnt * hap[0] << endl;
    } else {
        int cnt = c / w[1];
        cout << (LL)cnt * hap[1] << endl;
    }
    return 0;
}