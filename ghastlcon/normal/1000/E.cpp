#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#define N 300020
using namespace std;

int u[N], v[N];
vector<pair<int, int> > e[N];
int d[N], l[N];
bool k[N];

void DFS(int x, int p)
{
    static int t;
    int i;

    d[x] = l[x] = ++ t;
    for(i = 0; i < (signed)e[x].size(); i ++)
        if(!d[e[x].at(i).first])
        {
            DFS(e[x].at(i).first, x);
            l[x] = min(l[x], l[e[x].at(i).first]);
            if(l[e[x].at(i).first] > d[x])
                k[e[x].at(i).second] = true;
        }
        else if(e[x].at(i).first != p)
            l[x] = min(l[x], d[e[x].at(i).first]);

    return;
}

void Connect(int x, int k)
{
    int i;

    if(d[x] != -1)
        return;
    d[x] = k;

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(!::k[e[x].at(i).second])
            Connect(e[x].at(i).first, k);

    return;
}

void Farthest(int x, int p)
{
    int i;

    // printf("Visit %d\n", x);
    for(i = 0, d[x] = x; i < (signed)e[x].size(); i ++)
        if(e[x].at(i).first != p)
        {
            l[e[x].at(i).first] = l[x] + 1;
            Farthest(e[x].at(i).first, x);
            if(l[d[x]] < l[d[e[x].at(i).first]])
                d[x] = d[e[x].at(i).first];
        }

    return;
}

int main(void)
{
    int n, m;
    int i, c, x, y;

    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i ++)
    {
        scanf("%d %d", &u[i], &v[i]);
        e[-- u[i]].push_back(make_pair(-- v[i], i));
        e[   v[i]].push_back(make_pair(   u[i], i));
    }
    DFS(0, 0);
    // for(i = 0; i < m; i ++) cout << k[i] << ' '; cout << endl;

    memset(d, -1, sizeof(d));
    for(i = c = 0; i < n; i ++)
        if(d[i] == -1)
            Connect(i, c ++);
    // for(i = 0; i < m; i ++) cout << d[i] << ' '; cout << endl;

    for(i = 0; i < n; i ++)
        e[i].clear();
    for(i = 0; i < m; i ++)
        if(k[i])
        {
            e[d[u[i]]].push_back(make_pair(d[v[i]], 0));
            e[d[v[i]]].push_back(make_pair(d[u[i]], 0));
            // printf("%d -> %d\n", d[u[i]], d[v[i]]);
        }
    memset(d, 0, sizeof(d));
    memset(l, 0, sizeof(l));
    Farthest(0, 0);
    x = d[0];
    memset(d, 0, sizeof(d));
    memset(l, 0, sizeof(l));
    Farthest(x, x);
    y = d[x];

    // cout << x << ' ' << y << endl;
    printf("%d\n", l[y]);

    return 0;
}