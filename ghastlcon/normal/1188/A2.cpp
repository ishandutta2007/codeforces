#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 1020
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int w;
};

int u[N], v[N], w[N], d[N];
vector<int> e[N];
vector<Edge> o;

void DFS(int x, int p, int &v)
{
    int i;

    if(d[x] == 1 && !v)
        v = x;

    for(i = 0; i < (signed)e[x].size(); i ++)
        if(e[x].at(i) != p)
            DFS(e[x].at(i), x, v);

    return;
}

int main(void)
{
    int n;
    int i, j, p[4];

    scanf("%d", &n);
    for(i = 1; i < n; i ++)
    {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        e[u[i]].push_back(v[i]);
        e[v[i]].push_back(u[i]);
        d[u[i]] ++;
        d[v[i]] ++;
    }

    for(i = 1; i <= n; i ++)
        if(d[i] == 2)
        {
            printf("NO\n");
            break;
        }
    if(i > n)
    {
        printf("YES\n");
        for(i = 1; i < n; i ++)
        {
            p[0] = p[1] = p[2] = p[3] = 0;
            if(d[u[i]] == 1)
                p[0] = p[1] = u[i];
            else
            {
                for(j = 0; j < (signed)e[u[i]].size(); j ++)
                    if(e[u[i]].at(j) != v[i])
                    {
                        if(!p[0])
                            DFS(e[u[i]].at(j), u[i], p[0]);
                        else
                            DFS(e[u[i]].at(j), u[i], p[1]);
                    }
            }
            if(d[v[i]] == 1)
                p[2] = p[3] = v[i];
            else
            {
                for(j = 0; j < (signed)e[v[i]].size(); j ++)
                    if(e[v[i]].at(j) != u[i])
                    {
                        if(!p[2])
                            DFS(e[v[i]].at(j), v[i], p[2]);
                        else
                            DFS(e[v[i]].at(j), v[i], p[3]);
                    }
            }

            o.push_back((Edge){p[0], p[2], w[i] >> 1});
            o.push_back((Edge){p[1], p[3], w[i] >> 1});
            if(p[0] != p[1])
                o.push_back((Edge){p[0], p[1], -(w[i] >> 1)});
            if(p[2] != p[3])
                o.push_back((Edge){p[2], p[3], -(w[i] >> 1)});            
        }

        printf("%d\n", (int)o.size());
        for(i = 0; i < (signed)o.size(); i ++)
            printf("%d %d %d\n", o.at(i).u, o.at(i).v, o.at(i).w);
    }

    return 0;
}