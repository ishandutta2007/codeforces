#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define LL long long

using namespace std;

vector<vector<int> > a, cc;
vector<int> di, rr, clr, ans;
vector<bool> used;

void dfs(int v, int C){
    clr[v] = C;
    cc[C].pb(v);
    used[v] = true;
    rr[v] = 0;
    di[v] = 0;
    int x = 0, y = 0;
    for (int i = 0; i < a[v].size(); i++){
        if (!used[a[v][i]]){
            dfs(a[v][i], C);
            rr[v] = max(rr[v], rr[a[v][i]] + 1);
            di[v] = max(di[v], di[a[v][i]]);
            if (rr[a[v][i]] + 1 > y) y = rr[a[v][i]] + 1;
            if (x < y) swap(x, y);
        }
    }
    di[v] = max(di[v], x + y);
}

int main()
{

    int n, m, q;
    cin >> n >> m >> q;
    a.resize(n);
    cc.resize(n);
    di.resize(n);
    rr.resize(n);
    clr.resize(n);
    ans.resize(n);
    used.resize(n, false);
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x].pb(y);
        a[y].pb(x);
    }
    int C = 0;
    for (int i = 0; i < n; i++){
        if (!used[i]){
            dfs(i, C);
            ans[C] = di[i];
            C++;
        }
    }
    for (int i = 0; i < q; i++){
        int x, y, z;
        cin >> z;
        if (z == 1){
            cin >> x;
            x--;
            cout << ans[clr[x]] << "\n";
        } else {
            cin >> x >> y;
            x--, y--;
            if (clr[x] != clr[y]){
                x = clr[x];
                y = clr[y];
                if (cc[x].size() < cc[y].size()) swap(x, y);
                for (int j = 0; j < cc[y].size(); j++){
                    clr[cc[y][j]] = x;
                    cc[x].pb(cc[y][j]);
                }
                cc[y].clear();
                ans[x] = max(max(ans[x], ans[y]), (ans[x] + 1) / 2 + (ans[y] + 1) / 2 + 1);
            }
        }
    }

    return 0;
}