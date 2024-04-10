#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
 
 
using namespace std;
 

int n, m;
vector<pair<int, pair<int, int> > > v[1001];
bool used[1001];
int s, t;
vector<pair<pair<int, int>, pair<int, int> > > tr;


bool dfs(int u, int vertex) {
    used[u] = 1;
    if (u == vertex) {
        return 1;
    }
    for (int i = 0; i < (int)v[u].size(); i++) {
        int h = v[u][i].first;
        if (!used[h]) {
            if (dfs(h, vertex)) {
                tr.push_back(make_pair(make_pair(u, h), v[u][i].second));
                return 1;
            }
        }
    }
    return 0;
}


int timer, tin[1001], fup[1001];
int aa, bb, cc, dd;
vector<int> ans;
int sum = 2000000001;
int cnt[1001][1001];

 
bool dfs2(int vv, int p = -1) {
    bool info = 0;
    if (vv == t) {
        info = 1;
    }
    used[vv] = 1;
    tin[vv] = fup[vv] = timer++;
    for (size_t i=0; i<v[vv].size(); i++) {
        int to = v[vv][i].first;
        if (to == p)  {
            continue;
        }
        if (v[vv][i].second.second == dd) {
            continue;
        }        
        if (used[to]) {
            fup[vv] = min (fup[vv], tin[to]);
        } else {
            bool info1 = 0;
            if (dfs2(to, vv)) {
                info = 1;
                info1 = 1;
            }
            fup[vv] = min (fup[vv], fup[to]);
            if (fup[to] > tin[vv]) {
                if (info1 && cnt[to][vv] == 1) {
                    if (sum > v[vv][i].second.first + cc) {
                        sum = v[vv][i].second.first + cc;
                        ans.clear();
                        ans.push_back(dd);
                        ans.push_back(v[vv][i].second.second);
                    }
                } 
            }
        }
    }
    return info;
}
 


int main() {
    cin >> n >> m;
    cin >> s >> t;
    s--;
    t--;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        cnt[a][b]++;
        cnt[b][a]++;
        v[a].push_back(make_pair(b, make_pair(c, i + 1)));
        v[b].push_back(make_pair(a, make_pair(c, i + 1)));
    }
    for (int i = 0; i < n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    if (!dfs(s, t)) {
        cout << 0 << endl;
        cout << 0 << endl;
        return 0;
    }
    //cout << "opa" << endl;
    for (int ii = 0; ii < (int)tr.size(); ii++) {
        int a = tr[ii].first.first;
        int b = tr[ii].first.second;
        int c = tr[ii].second.first;
        dd = tr[ii].second.second;
        if (n == 62 && dd == 52) {
       //     cout << c << endl;
        }
        memset(used, 0, sizeof(used));
        aa = a;
        bb = b;
        cc = c;
       // cout << a << ' ' << b << endl;
        timer = 0;
        cnt[a][b]--;
        cnt[b][a]--;
        bool info = dfs2(s);
        cnt[a][b]++;
        cnt[b][a]++;
        //cout << a << ' ' << b << endl;
        if (!info) {
            sum = min(sum, cc);
            if (sum == cc) {
                ans.clear();
                ans.push_back(dd);
            }
        }
    }
    if (sum == 2000000001) {
        cout << -1 << endl;
    } else {
        cout << sum << endl;
        cout << (int)ans.size() << endl;
        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}