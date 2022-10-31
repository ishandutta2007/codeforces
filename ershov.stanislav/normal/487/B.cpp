#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <string>
#include <cstring>

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9+100;
const ll lINF = 1e18;
const double E = 2.718281828459045;

int n, l, s, a[111111], last[111111], ans[111111], mn[111111];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> s >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    last[n] = n;
    deque<pair<int, int> > q1, q2;
    for (int i = n-1; i >= 0; i--) {
        last[i] = min(last[i+1], i);
        while (q1.size() && q1.front().sc > i) q1.pop_front();
        while (q2.size() && q2.front().sc > i) q2.pop_front();
        if (q1.empty()) q1.pb(mp(a[i], i));
        if (q2.empty()) q2.pb(mp(a[i], i));
        while (last[i]>0 && max(abs(a[last[i]-1] - q1.front().fs),
                        abs(a[last[i]-1] - q2.front().fs)) <= s) {
            last[i]--;
            while (q1.size() && q1.back().fs > a[last[i]]) q1.pop_back();
            q1.push_back(mp(a[last[i]], last[i]));
            while (q2.size() && q2.back().fs < a[last[i]]) q2.pop_back();
            q2.push_back(mp(a[last[i]], last[i]));
        }
        //for (int i = 0; i < q1.size(); i++) cout << q1[i].fs << ' ' << q1[i].sc << 'r';
        //cout << endl;
        //for (int i = 0; i < q2.size(); i++) cout << q2[i].fs << ' ' << q2[i].sc << 'r';
        //cout << endl;
        //cout << endl;
    }
    //for (int i = 0; i < n; i++) cout << last[i];
    //cout << endl;
    deque<pair<int, int> > q;
    for (int i = 1, ll = 0, rr = 0; i <= n; i++) {
        while (rr < i - l + 1) {
            while (q.size() && q.back().fs > ans[rr]) q.pop_back();
            q.push_back(mp(ans[rr], rr));
            rr++;
        }
        ll = last[i-1];
        while (q.size() && q.front().sc < ll) q.pop_front();
        if (q.size()) ans[i] = q.front().fs + 1;
        else ans[i] = INF;
        //cout << ans[i] << ' ';
    }
    if (ans[n] < INF) cout << ans[n] << endl;
    else cout << -1 << endl;
    return 0;
}