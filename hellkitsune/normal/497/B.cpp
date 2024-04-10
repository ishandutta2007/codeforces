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
int a[100000];
int cnt1[100001], cnt2[100001];
vector<PII> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    cnt1[0] = a[0] == 1;
    for (int i = 1; i < n; ++i)
        cnt1[i] = cnt1[i - 1] + (a[i] == 1);
    cnt2[0] = a[0] == 2;
    for (int i = 1; i < n; ++i)
        cnt2[i] = cnt2[i - 1] + (a[i] == 2);
    for (int t = 1; t <= n; ++t) {
        int ind = 0;
        bool flag = true;
        int win1 = 0, win2 = 0;
        bool last1 = false;
        while (ind < n) {
            int lo = ind, hi = n, mid;
            int sub1 = (ind == 0) ? 0 : cnt1[ind - 1];
            int sub2 = (ind == 0) ? 0 : cnt2[ind - 1];
            while (lo < hi) {
                mid = (lo + hi) >> 1;
                if (cnt1[mid] - sub1 < t && cnt2[mid] - sub2 < t)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            if (hi == n) {
                flag = false;
                break;
            }
            if (cnt1[hi] - sub1 == t) ++win1, last1 = true;
            else ++win2, last1 = false;
            ind = hi + 1;
        }
        if (flag && ((win1 > win2 && last1) || (win2 > win1 && !last1))) {
            ans.pb(mp(max(win1, win2), t));
        }
    }
    sort(ans.begin(), ans.end());
    cout << (int)ans.size() << '\n';
    REP(i, ans.size())
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    return 0;
}