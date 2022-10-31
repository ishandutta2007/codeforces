#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;

#ifdef DEBUG
#define dout(x) cerr<<x;
#else
#define dout(x)
#endif

using namespace std;

int n;
int a[111111];
int cnt1[111111], cnt2[111111];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    vector<pair<int, int> > ans;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt1[i+1] = cnt1[i];
        cnt2[i+1] = cnt2[i];
        if (a[i] == 1) cnt1[i+1] = cnt1[i]+1;
        else cnt2[i+1] = cnt2[i]+1;
    }
    for (int t = 1; t <=n; t++) {
        int l=0, c1=0, c2=0;
        int wins1 = 0, wins2 = 0, last = 0;
        while (l < n) {
            int L = l, R = n+1;
            while (R - L > 1) {
                int mid = (L+R)/2;
                if (cnt1[mid] < c1 + t) {
                    L = mid;
                } else {
                    R = mid;
                }
            }
            L++;
            int L1 = l;
            R = n+1;
            while (R - L1 > 1) {
                int mid = (L1+R)/2;
                if (cnt2[mid] < c2 + t) {
                    L1 = mid;
                } else {
                    R = mid;
                }
            }
            L1++;
            if (L < L1) wins1++, last = 1;
            else wins2++, last = 2;
            int mn = min(L, L1);
            if (max(cnt1[mn]-c1, cnt2[mn]-c2) < t) {
                last = 0;
                break;
            }
            c1 = cnt1[mn];
            c2 = cnt2[mn];
            l=mn;
        }
        if (last == 1 && wins1 > wins2) {
            ans.pb(mp(wins1, t));
        }
        if (last == 2 && wins2 > wins1) {
            ans.pb(mp(wins2, t));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].fs << ' ' << ans[i].sc << endl;
    }
    return 0;
}