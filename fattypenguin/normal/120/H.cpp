#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <assert.h>
#include <queue>
#include <iostream>

const int max_edge = 548576,
          max_vertex = 400*200,
          inf = 0xfffffff;

using namespace std;

#define PB push_back

struct EDGE  {
    int next,u,w,v,r;
    bool reversed;
} edge[max_edge];

int last = 0,V[max_vertex],n,s,t;
int height[max_vertex],nheight[max_vertex];

void insert(int u,int v,int w) {
    edge[last].u = u;
    edge[last].v = v;
    edge[last].w = w;
    edge[last].r = last + 1;
    edge[last].next = V[u];
    edge[last].reversed = false;
    V[u] = last++;

    edge[last].u = v;
    edge[last].v = u;
    edge[last].w = 0;
    edge[last].r = last - 1;
    edge[last].next = V[v];
    edge[last].reversed = true;
    V[v] = last++;
}

//AugPath(n,s,s,t,0xfffffff,edge);
long AugPath(int n,int u,int s,int t,int push,EDGE edge[]) {
    if (u == t)
        return push;
    int flow = push,minheight = n-1;
    for (int i = V[u];i != -1;i = edge[i].next)
        if (edge[i].w) {
            if (height[edge[i].v] + 1 == height[u]) {
                int delta = flow < edge[i].w ? flow : edge[i].w,f;
                if (delta) delta = AugPath(n,edge[i].v,s,t,delta,edge);
                edge[i].w -= delta;
                edge[edge[i].r].w += delta;
                flow -= delta;
                if (0 == flow || height[s] >= n) return push - flow;
            }
            if (height[edge[i].v] < minheight) minheight = height[edge[i].v];
        }
    if (!(push - flow)) {
        nheight[height[u]]--;
        if (!nheight[height[u]]) height[s] = n;
        height[u] = ++minheight;
        nheight[height[u]]++;
    }
    return push - flow;
}

map<string,int> pr;
string stand[max_vertex];
string ans[207];
int ID[207],tt;
char buf[10007],ret[100007];
bool vis[max_vertex];
queue<int> Q;
int total;

void dfs(int now,int dep,int ID,int LEN)
{
    if (now>=LEN)
    {
        if (dep==0) return;
        ret[dep]=0;
        string t(ret);
        if (pr.find(t)==pr.end())
        {
            pr[t] = total++;
            stand[total-1] = t;
            insert(s,total-1,1);
        }
        insert(pr[t],ID,1);
        return;
    }
    dfs(now+1,dep,ID,LEN);
    if (dep>=4) return;
    ret[dep] = buf[now];
    dfs(now+1,dep+1,ID,LEN);
}

int main() {
/*
    last = 0;
    for (int i = 0;i <= m*2;++i)
        V[i] = -1;
    t = n-1; s = 0;
    memset(height,0,sizeof(height));
    memset(nheight,0,sizeof(nheight));
    nheight[0] = VERTEXS; int flow = 0;
    while (height[s] < VERTEXS)
        flow += AugPath(n,s,s,t,inf,edge);
    printf("%d\n",flow);
*/
    int Cases;
    //cin >> Cases;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N;
    while (cin >> N)
    {
        pr.clear();
        last = 0,s=0,t=1;
        total = 2;
        for (int i = 0;i < 400*N;++i) V[i] = -1;
        for (int i = 0;i < N;++i) ID[i] = total++;
        for (int i = 0;i < N;++i)
        {
            scanf("%s",buf);
            string t = "";
            int len = strlen(buf);
            dfs(0,0,ID[i],len);
        }
        for (int i = 0;i < N;++i)
            insert(ID[i],t,1);
        n = total;
        memset(height,0,sizeof(height));
        memset(nheight,0,sizeof(nheight));
        nheight[0] = n; int flow = 0;
        while (height[s] < n)
            flow += AugPath(n,s,s,t,inf,edge);
        if (flow != N)
        {
            assert(flow<N);
            cout << -1<<endl;
            continue;
        }
        while (!Q.empty()) Q.pop();
        for (int i = 0;i < total;++i) vis[i] = false;
        vis[s] = true;
        Q.push(s);
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int i = V[now];i!=-1;i=edge[i].next)
                if (edge[i].w)
                {
                    if (!vis[edge[i].v])
                    {
                        vis[edge[i].v]=1;
                        Q.push(edge[i].v);
                    }
                }
        }
        int ttt= 0;
        for (int i = 0;i < last;++i)
        {
            if (!edge[i].w)
            {
            //    cout<<edge[i].u <<" " << edge[i].v << endl;
                if (edge[i].u > N+1 && edge[i].v <= N+1 && edge[i].v > 1)
                {
                    ++ttt;
                    ans[edge[i].v-2] = stand[edge[i].u];
                }
            }
        }
       // cout<<ttt<<endl;
        assert(ttt==N);
        for (int i = 0;i < N;++i)
            cout<<ans[i]<<endl;
    }
    return 0;

}