#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 5020
#define M 100020
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int w;
    int i;

    Edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w)
    {
        return;
    }

    bool operator<(const Edge &that) const
    {
        return this -> w < that.w;
    }
};

int n, m, k;
vector<Edge> e[2];
int f[N];
bool u[M];

int GetUFS(int x)
{
    int i, t;

    for(i = x; f[i] > -1; i = f[i])
        ;
    while(x != i)
    {
        t = f[x];
        f[x] = i;
        x = t;
    }

    return i;
}

bool MergeUFS(int x, int y)
{
    // printf("ufs: %d %d %d %d\n",x,y,GetUFS(x),GetUFS(y));
    x = GetUFS(x);
    y = GetUFS(y);
    if(x == y)
        return false;

    if(f[x] > f[y])
        swap(x, y);
    f[x] += f[y];
    f[y] = x;

    return true;
}

int Kruskal(int v)
{
    int i, j, k, c;

    for(i = 0; i < n; i ++)
        f[i] = -1;

    for(i = j = k = c = 0; k < n - 1 && (i < (signed)e[0].size() || j < (signed)e[1].size()); )
        if(i < (signed)e[0].size() && j < (signed)e[1].size())
            if(e[0].at(i).w + v <= e[1].at(j).w)
            {
                if(c < ::k && MergeUFS(e[0].at(i).u, e[0].at(i).v))
                {
                    // printf("select %d\n",i);
                    k ++;
                    c ++;
                    u[e[0].at(i).i] = true;
                }
                i ++;
            }
            else
            {
                if(MergeUFS(e[1].at(j).u, e[1].at(j).v))
                {
                    k ++;
                    u[e[1].at(j).i] = true;
                }
                j ++;
            }
        else if(i < (signed)e[0].size())
        {
            if(c < ::k && MergeUFS(e[0].at(i).u, e[0].at(i).v))
            {
                k ++;
                c ++;
                u[e[0].at(i).i] = true;
            }
            i ++;
        }
        else
        {
            // printf("%d %d %d %d\n",e[1].at(j).u,e[1].at(j).v,GetUFS(e[1].at(j).u),GetUFS(e[1].at(j).v));
            if(MergeUFS(e[1].at(j).u, e[1].at(j).v))
            {
                // printf("try select %d\n",j);
                k ++;
                u[e[1].at(j).i] = true;
            }
            j ++;
        }
    // printf("final select %d\n",k);

    return k == n - 1 ? c : -1;
}

void BSFind(void)
{
    int l, m, r;
    int i, c;

    if(Kruskal(0) == -1)
    {
        printf("-1\n");

        return;
    }

    for(l = -100000, r = 100001; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if(Kruskal(m) >= k)
            l = m;
        else
            r = m;
    }

    // printf("%d %d\n",l,Kruskal(l));

    for(i = 0; i < ::m; i ++)
        u[i] = false;
    if(Kruskal(l) == k)
    {
        for(i = c = 0; i < ::m; i ++)
            c += u[i];
        printf("%d\n", c);
        for(i = 0; i < ::m; i ++)
            if(u[i])
                printf("%d ", i + 1);
        printf("\n");
    }
    else
        printf("-1\n");

    return;
}

int main(void)
{
    int i;
    Edge t;

    scanf("%d %d %d", &n, &m, &k);
    for(i = 0; i < m; i ++)
    {
        scanf("%d %d %d", &t.u, &t.v, &t.w);
        t.i = i;
        if((-- t.u) > (-- t.v))
            swap(t.u, t.v);
        e[!!t.u].push_back(t);
    }
    sort(e[0].begin(), e[0].end());
    sort(e[1].begin(), e[1].end());

    // for(Edge t:e[0])printf("%d<->%d:%d\n",t.u,t.v,t.w);
    // printf("\n");
    // for(Edge t:e[1])printf("%d<->%d:%d\n",t.u,t.v,t.w);
    // printf("\n");
    BSFind();

    return 0;
}