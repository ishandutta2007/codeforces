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

int n, m, w[1111], b[1111];
int used[1111], cnt;
vector<pair<int, int> > vv;
long long ans;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (!used[b[i]-1]) {
            cnt++;
            vv.pb(mp(w[b[i] - 1], b[i] - 1));
        }
        used[b[i]-1] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) vv.pb(mp(w[i], i));
    }
    reverse(vv.begin(), vv.end());
    for (int i = 0; i < m; i++) {
        vv.pb(mp(w[b[i] - 1], b[i]-1));
    }
    for (int i = n; i<vv.size(); i++) {
        for (int i = 0; i < n; i++) {
            used[i] = 0;
        }
        for (int j = i - 1; j >=0 && vv[j].sc!=vv[i].sc; j--) {
            used[vv[j].sc] = 1;
        }
        for (int j = 0; j < n; j++) {
            if (used[j]) ans+=w[j];
        }
    }
    cout << ans;
    return 0;
}