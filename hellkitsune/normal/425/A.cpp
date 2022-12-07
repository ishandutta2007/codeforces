#include <cstdio>
#include <cmath>
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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, a[200], ans = -2e9;

int main() {
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    for (int l = 0; l < n; ++l) {
        set<PII> b, c;
        REP(i, n)
            c.insert(mp(-a[i], i));
        int cur = 0;
        for (int r = l; r < n; ++r) {
            cur += a[r];
            int delta = 0;
            c.erase(mp(-a[r], r));
            b.insert(mp(a[r], r));
            set<PII>::iterator bit = b.begin(), cit = c.begin();
            for (int i = 0; i < k; ++i) {
                if (bit == b.end() || cit == c.end())
                    break;
                if (bit->first + cit->first >= 0)
                    break;
                delta -= bit->first + cit->first;
                ++bit; ++cit;
            }
            ans = max(ans, cur + delta);
        }
    }
    cout << ans << endl;
    return 0;
}