#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int tests;
int n;

vector <vector <int> > vertex;
vector <pair <int, int> > ans;
vector <int> deg;
bool flag = true;

vector <int> dfs(int v, int from) {
    vector <vector <int> > len1;
    vector <vector <int> > len2;

    for (auto e : vertex[v]) {
        if (e != from) {
            vector <int> res = dfs(e, v);
            if (!flag) {
                return vector <int>();
            }
            if ((int) res.size() == 1u) {
                len1.pb(res);
            } else {
                len2.pb(res);
            }
        }
    }

    while (!len1.empty() && !len2.empty()) {
        if (deg[v] % 2 == 0) {
            ans.pb(mp(v, len2.back()[1]));
            ans.pb(mp(len2.back()[1], len2.back()[0]));
            ans.pb(mp(v, len1.back()[0]));
            deg[v] -= 2;
            deg[len2.back()[1]] -= 2;
            deg[len2.back()[0]] -= 1;
            deg[len1.back()[0]] -= 1;
            len1.pop_back();
            len2.pop_back();
        } else {
            ans.pb(mp(v, len1.back()[0]));
            deg[v] -= 1;
            deg[len1.back()[0]] -= 1;
            len1.pop_back();
        }
    }
    if (len1.empty() && len2.empty()) {
        vector <int> res;
        res.pb(v);

        return res;
    }
    if (len1.empty() && !len2.empty()) {
        if (len2.size() == 1u) {
            if (deg[v] % 2 != 0) {
                flag = false;

                return vector <int>();
            } else {
                ans.pb(mp(v, len2.back()[1]));
                ans.pb(mp(len2.back()[1], len2.back()[0]));
                deg[v] -= 1;
                deg[len2.back()[1]] -= 2;
                deg[len2.back()[0]] -= 1;
                len2.pop_back();

                vector <int> res;
                res.pb(v);
                return res;
            }
        } else {
            flag = false;

            return vector <int>();
        }
    }
    if (!len1.empty() && len2.empty()) {
        if (len1.size() >= 3u) {
            flag = false;

            return vector <int>();
        }
        if (len1.size() == 2u) {
            if (deg[v] % 2 == 0) {
                flag = false;

                return vector <int>();
            } else {
                ans.pb(mp(v, len1.back()[0]));
                deg[v] -= 1;
                deg[len1.back()[0]] -= 1;
                len1.pop_back();

                vector <int> res = len1[0];
                res.pb(v);

                return res;
            }
        }
        if (len1.size() == 1u) {
            if (deg[v] % 2 == 0) {
                vector <int> res = len1[0];
                res.pb(v);

                return res;
            } else {
                ans.pb(mp(v, len1[0][0]));
                deg[v] -= 1;
                deg[len1[0][0]] -= 1;
                len1.pop_back();

                vector <int> res;
                res.pb(v);

                return res;
            }
        }
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> tests;
    for (int tc = 0; tc < tests; tc++) {
        cin >> n;

        vertex.resize(n);
        deg.resize(n);
        for (int i = 0; i < n; i++) {
            vertex[i].clear();
            deg[i] = 0;
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            vertex[u].pb(v);
            vertex[v].pb(u);
            deg[u]++;
            deg[v]++;
        }

        flag = true;
        ans.clear();
        
        vector <int> res = dfs(0, -1);
        if (!flag) {
            if (res.size() == 2u) {
                ans.pb(mp(res[0], res[1]));
            }
        }
        if (!flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            assert((int) ans.size() == n - 1);
            for (int i = 0; i < n - 1; i++) {
                cout << ans[i].fs + 1 << ' ' << ans[i].sc + 1 << endl;
            }
        }
    }

    return 0;
}