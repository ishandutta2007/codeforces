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
set<int> se;
map<int, int> ma;
int rev[200005], mac = 0;
vector<int> g[200005];
int from[100000], to[100000];
int cnt[200005] = {};
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        cin >> from[i] >> to[i];
        se.insert(from[i]);
        se.insert(to[i]);
    }
    for (int x : se) rev[mac] = x, ma[x] = mac++;
    REP(i, n) from[i] = ma[from[i]], to[i] = ma[to[i]];
    REP(i, n) ++cnt[from[i]], ++cnt[to[i]];
    REP(i, n) g[from[i]].pb(to[i]);
    REP(i, n) g[to[i]].pb(from[i]);
    int v = 0;
    while (cnt[v] != 1) ++v;
    ans.pb(rev[v]);
    int pre = -1;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int to : g[v]) if (to != pre) {
            flag = true;
            pre = v;
            v = to;
            ans.pb(rev[v]);
            break;
        }
    }
    for (int x : ans)
        cout << x << ' ';
    cout << endl;
    return 0;
}