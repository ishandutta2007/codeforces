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

int n, p[444444], l[444444], sum[444444], q, ans[444444], r[444444];
pair<int, pair<int, int> > xy[444444];

set<int> d;
map<int, int> sh;
map<int, int> opmx;
vector<int> dd;

int get (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += sum[r];
	return result;
}

void inc (int i, int delta)
{
    r[i]+=delta;
	for (; i < 444444; i = (i | (i+1)))
		sum[i] += delta;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> l[i];
        d.insert(p[i]);
        d.insert(p[i]+l[i]);
        opmx[p[i]] = max(opmx[p[i]], p[i]+l[i]);
    }
    int cur = 0;
    for (auto i : d) {
        dd.pb(i);
        sh[i] = dd.size() - 1;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> xy[i].fs >> xy[i].sc.fs;
        xy[i].fs--, xy[i].sc.fs--;
        xy[i].sc.sc = i;
    }
    sort(xy, xy+q);
    cur = dd.size();
    stack<int> s;
    for (int i = q-1; i>=0 ; i--) {
        while (cur > sh[p[xy[i].fs]]) {
            cur--;
            s.push(cur);
            if (cur < dd.size() -1 ) inc(cur, dd[cur + 1] - dd[cur]);
            while (s.size() && s.top() < sh[opmx[dd[cur]]]) {
                int j = s.top();
                s.pop();
                inc(j, -r[j]);
            }
            dout (cur << ' ' << opmx[dd[cur]] << ' ' << s.size()<< endl);
        }
        dout(xy[i].sc.sc + 1 << ' ');
        for (int i = 0; i <dd.size(); i++) dout(r[i] << ' ');
        dout(endl);
        ans[xy[i].sc.sc] = get(sh[p[xy[i].sc.fs]] -1) - get(sh[p[xy[i].fs]]);
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}