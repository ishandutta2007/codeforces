#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

vector< vector<int> > a, components;
vector<int> g[1001005], gr[1001005], G[1001005];
int n,m,numbcomp[1001005],anscomp[1001005];

pii e[1001005];
char u[1001005];
vector<int> curord, curcomp;

void dfs1(int v) {
    u[v] = 1;
    for (int i = 0; i < g[v].size(); ++i)
        if (!u[g[v][i]])
            dfs1(g[v][i]);
    curord.push_back(v);
}

void dfs2(int v) {
    u[v] = 1;
    curcomp.push_back(v);
    for (int i = 0; i < gr[v].size(); ++i)
        if (!u[gr[v][i]])
            dfs2(gr[v][i]);
}

void dfs3(int v) {
    u[v] = 1;
    for (int i = 0; i < G[v].size(); ++i)
        if (!u[G[v][i]])
            dfs3(G[v][i]);
    curord.push_back(v);
}

int main()
{
    scanf("%d%d",&n,&m);
    a = vector< vector<int> >(n + 5, vector<int>(m + 5, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            e[j] = make_pair(a[i][j], i * m + j);
        sort(e, e + m);
        for (int j = 0; j + 1 < m; ++j) {
            if (e[j].first == e[j+1].first) {
                g[e[j].second].push_back(e[j+1].second);
                gr[e[j+1].second].push_back(e[j].second);
            }
            g[e[j+1].second].push_back(e[j].second);
            gr[e[j].second].push_back(e[j+1].second);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            e[j] = make_pair(a[j][i], j * m + i);
        sort(e, e + n);
        for (int j = 0; j + 1 < n; ++j) {
            if (e[j].first == e[j+1].first) {
                g[e[j].second].push_back(e[j+1].second);
                gr[e[j+1].second].push_back(e[j].second);
            }
            g[e[j+1].second].push_back(e[j].second);
            gr[e[j].second].push_back(e[j+1].second);
        }
    }

    for (int i = n * m; i--; )
        if (!u[i])
            dfs1(i);
    for (int i = n * m; i--; )
        u[i] = 0;
    for (int i = n * m; i--; ) {
        int v = curord[i];
        if (!u[v]) {
            dfs2(v);
            for (int j = 0; j < curcomp.size(); ++j)
                numbcomp[curcomp[j]] = components.size();
            components.push_back(curcomp);
            curcomp.clear();
        }
    }

    for (int i = n * m; i--; ) {
        for (int j = 0; j < g[i].size(); ++j) {
            G[numbcomp[i]].push_back(numbcomp[g[i][j]]);
        }
    }

    curord.clear();
    for (int i = n * m; i--; )
        u[i] = 0;
    for (int i = 0; i < components.size(); ++i)
        if (!u[i])
            dfs3(i);

    for (int i = 0; i < curord.size(); ++i) {
        int curcolor = 0;
        int curv = curord[i];
        for (int j = 0; j < G[curv].size(); ++j)
            curcolor = max(curcolor, anscomp[G[curv][j]]);
        ++curcolor;
        anscomp[curv] = curcolor;
        for (int j = 0; j < components[curv].size(); ++j) {
            int curx = components[curv][j] % m;
            int cury = components[curv][j] / m;
            a[cury][curx] = curcolor;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}