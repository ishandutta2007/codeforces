#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

int n, m, t=0, l[111111], r[111111], d[111111];
string s[111111];
vector<int> a[111111];
vector<int> p[111111];
map<pair<int, ii>, int> ans;

void dfs(int y, int i) {
    p[y].push_back(i);
    l[i]=t++; d[i]=y;
    for (int j=0; j<a[i].size(); j++) dfs(y+1, a[i][j]);
    r[i]=t;
}

bool c1(int a, int b) { return (l[a] < l[b]); }
bool c2(int a, int b) { return (l[a] < r[b]); }

int get(int v, int k) {
    k+=d[v];
    int left=lower_bound(p[k].begin(), p[k].end(), v, c1) - p[k].begin(),
        right=lower_bound(p[k].begin(), p[k].end(), v, c2) - p[k].begin();
    set<string> s2;
    int &c=ans[make_pair(k, ii(left, right))];
    if (c) return c;
    for (int i=left; i<right; i++) s2.insert(s[p[k][i]]);
    return c=s2.size();
}

int main()
{
    cin >> n;
    int z, r, q;
    for (int i=1; i<=n; i++) cin >> s[i] >> z, a[z].push_back(i);
    dfs(0, 0);
    cin >> m;
    for (int i=0; i<m; i++) cin >> r >> q, cout << get(r, q) << endl;
    return 0;
}