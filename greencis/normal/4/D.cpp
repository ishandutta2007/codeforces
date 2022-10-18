#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,w,h;
vector<int> ansv;

struct entry {
    int w,h,idx;
} e[5005];

vector<short> g[5005];
int d[5005], p[5005];

int dfs(int v) {
    if (!d[v]) {
        int mx = 1, mxi = -1;
        for (int i = 0; i < g[v].size(); ++i) {
            int val = dfs(g[v][i]) + 1;
            if (val > mx) mx = val, mxi = g[v][i];
        }
        d[v] = mx;
        p[v] = mxi;
    }
    return d[v];
}

int main()
{
    cin >> n >> w >> h;
    for (int i = 0; i < n; ++i) {
        cin >> e[i].w >> e[i].h;
        e[i].idx = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (e[i].w < e[j].w && e[i].h < e[j].h)
                g[i].push_back(j);
        }
    }

    int ans = 0, ansi;
    for (int i = 0; i < n; ++i) {
        int val = dfs(i);
        if (ans < val && w < e[i].w && h < e[i].h) {
            ans = val;
            ansi = i;
        }
    }
    if (ans == 0) { cout << 0; return 0; }
    int curv = ansi;
    while (curv != -1) {
        ansv.push_back(curv + 1);
        curv = p[curv];
    }
    cout << ansv.size() << endl;
    for (int i = 0; i < ansv.size(); ++i) cout << ansv[i] << " ";

    return 0;
}