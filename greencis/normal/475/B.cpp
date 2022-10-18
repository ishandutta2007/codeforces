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

int n,m,components;
char hor[99],ver[99];
vector< int > g[9999],gr[9999];
int u[9999];
vector<int> order;

void dfs1(int curv){
    u[curv] = 1;
    for (int i = 0; i < g[curv].size(); ++i)
        if (!u[g[curv][i]])
            dfs1(g[curv][i]);
    order.push_back(curv);
}

void dfs2(int curv) {
    u[curv] = 1;
    for (int i = 0; i < gr[curv].size(); ++i)
        if (!u[gr[curv][i]])
            dfs2(gr[curv][i]);
}

int main()
{
    cin >> n >> m >> hor >> ver;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (hor[i] == '<') {
                if (j > 0) g[i * 100 + j].push_back(i * 100 + j-1),
                    gr[i * 100 + j-1].push_back(i * 100 + j);
            } else {
                if (j < m-1) g[i * 100 + j].push_back(i * 100 + j+1),
                    gr[i * 100 + j+1].push_back(i * 100 + j);
            }

            if (ver[j] == '^') {
                if (i > 0) g[i * 100 + j].push_back((i-1) * 100 + j),
                    gr[(i-1) * 100 + j].push_back(i * 100 + j);
            } else {
                if (i < n-1) g[i * 100 + j].push_back((i+1) * 100 + j),
                    gr[(i+1) * 100 + j].push_back(i * 100 + j);
            }
        }
    }

    for (int i = 0; i < 9999; ++i)
        u[i] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!u[i*100 + j])
                dfs1(i*100 + j);
        }
    }

    for (int i = 0; i < 9999; ++i)
        u[i] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int curv = order[n*m-i-1];
            if (!u[curv]) {
                dfs2(curv);
                ++components;
            }
        }
    }

    if (components > 1 || components < 0) cout << "NO";
    else cout << "YES";

    return 0;
}