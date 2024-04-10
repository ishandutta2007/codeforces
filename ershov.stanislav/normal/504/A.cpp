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

int n, cnt[111111], sum[111111];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n;
    set<pair<int, int> > s;
    vector<pair<int, int> > ans;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &cnt[i], &sum[i]);
        if (cnt[i]) s.insert(mp(cnt[i], i));
    }
    while (s.size()) {
        pair<int, int> cur = *s.begin();
        int nxt = sum[cur.sc];
        ans.pb(mp(cur.sc, sum[cur.sc]));
        s.erase(cur);
        s.erase(mp(cnt[nxt], nxt));
        sum[nxt]^=cur.sc;
        cnt[nxt] --;
        if (cnt[nxt]) s.insert(mp(cnt[nxt], nxt));
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].fs, ans[i].sc);
    }
    return 0;
}