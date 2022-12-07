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
int v[100000], c[100000], l[100000], r[100000];
vector<int> g[300001];
int d[200001] = {};
vector<int> p[200001], pp[200001], px[200001];
vector<int> t;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> v[i] >> c[i] >> l[i] >> r[i];
    REP(i, n) g[c[i] + l[i] + r[i]].pb(i);
    int ans = 0;
    REP(i, 200001) if (!g[i].empty()) {
        for (int x : g[i]) if ((!l[x] || d[l[x]]) && d[l[x] + c[x]] < d[l[x]] + v[x]) {
            d[l[x] + c[x]] = d[l[x]] + v[x];
            p[l[x] + c[x]].pb(l[x]);
            pp[l[x] + c[x]].pb((int)p[l[x]].size() - 1);
            px[l[x] + c[x]].pb(x);
        }
        int ind = i;
        if (d[ind] > ans) {
            int pind = (int)p[ind].size() - 1;
            ans = d[ind];
            t.clear();
            while (ind) {
                t.pb(px[ind][pind]);
                int nind = p[ind][pind];
                pind = pp[ind][pind];
                ind = nind;
            }
        }
        for (int x : g[i]) {
            int pos = l[x] + c[x];
            d[pos] = 0;
            p[pos].clear();
            pp[pos].clear();
            px[pos].clear();
        }
    }
    cout << (int)t.size() << '\n';
    for (int i = (int)t.size() - 1; i >= 0; --i)
        cout << t[i] + 1 << ' ';
    cout << '\n';
    return 0;
}