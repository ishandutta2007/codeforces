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

int n, m, k[111111], ans[111111];
vector<pair<int, pair<int, int> > > act;
vector<pair<int, pair<int, int> > > part;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n;
    part.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> part[i].fs >> part[i].sc.fs;
        part[i].sc.sc = i;
    }
    cin >> m;
    act.resize(m);
    for (int i = 0; i < m; i++) {
        act[i].sc.sc = i;
        cin >> act[i].fs >> act[i].sc.fs >> k[i];
    }
    sort(act.begin(), act.end());
    sort(part.begin(), part.end());
    set<pair<int, int> > s;
    for (int i = 0, j=0; i < part.size(); i++) {
        while (j < m && act[j].fs <= part[i].fs) {
            s.insert(act[j].sc);
            j++;
        }
        if (s.lower_bound(mp(part[i].sc.fs, -INF)) == s.end()) {
            cout << "NO\n";
            return 0;
        }
        int t = s.lower_bound(mp(part[i].sc.fs, -INF))->sc;
        ans[part[i].sc.sc] = t;
        k[t]--;
        if (k[t] == 0) s.erase(s.lower_bound(mp(part[i].sc.fs, -INF)));
    }
    cout << "YES\n";
    for (int i = 0; i < part.size(); i++) {
        cout << ans[i] + 1 << ' ';
    }
    return 0;
}