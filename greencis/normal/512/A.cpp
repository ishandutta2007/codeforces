#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,len[999];
char p[999][999];
vector<int> g[999];
int u[999];

void fail() {
    printf("Impossible");
    exit(0);
}

bool dfs2(int v) {
    u[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (u[to] == 0) {
            if (dfs2(to)) return true;
        } else if (u[to] == 1) {
            return true;
        }
    }
    u[v] = 2;
    return false;
}

vector<int> ans;

void dfs(int v) {
    if (u[v]) return;
    u[v] = 1;
    for (int i = 0; i < g[v].size(); ++i)
        dfs(g[v][i]);
    ans.push_back(v);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int curidx = 0;
            while (p[i][curidx] == p[j][curidx]) ++curidx;
            if (p[i][curidx] != 0 && p[j][curidx] != 0) {
                g[p[i][curidx] - 'a'].push_back(p[j][curidx] - 'a');
            } else if (p[j][curidx] == 0 && p[i][curidx] != 0) {
                fail();
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (dfs2(i)) fail();
    }
    for (int i = 0; i < 26; ++i) u[i] = 0;
    for (int i = 0; i < 26; ++i) dfs(i);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < 26; ++i) {
        cout << char(ans[i] + 'a');
    }

    return 0;
}