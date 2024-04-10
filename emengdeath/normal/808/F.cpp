#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 110
using namespace std;
int n,m,s,t;
int d[maxn];
const long long inf = 1e18;
struct edge{
    int to,rev; //revtovector
    long long val;
    edge (int _to,long long _val,int _rev) //
    {
        to=_to;
        val=_val;
        rev=_rev;
    }
};
vector<edge> e[maxn];
void addedge(int x,int y,long long w)
{
    e[x].push_back(edge(y,w,e[y].size()));
    e[y].push_back(edge(x,0,e[x].size()-1));
}
bool bfs()
{
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<e[x].size();i++)
        {
            int y=e[x][i].to;
            if(d[y]==-1 && e[x][i].val)
            {
                q.push(y);
                d[y]=d[x]+1;
            }
        }
    }
    if(d[t]==-1)
        return 0;
    else
        return 1;
}
long long dfs(int x,long long low) //xlowx
{
    if(x==t || low==0)
        return low;
    long long totflow=0; //totflowx
    for(int i=0;i<e[x].size();i++)
    {
        int y=e[x][i].to;
        int rev=e[x][i].rev;
        if(d[y]==d[x]+1 && e[x][i].val) //yx  >0
        {
            long long a=dfs(y,min(low,e[x][i].val)); //a
            e[x][i].val-=a;
            e[y][rev].val+=a;
            low-=a;
            totflow+=a;
            if(low==0) //x
                return totflow;
        }
    }
    if(low!=0) //xdfsx
        d[x]=-1;
    return totflow;
}
long long dinic()
{
    long long ans = 0;
    while(bfs())
        ans+=dfs(s,inf);
    return ans;
}
struct node{
    int p, c, l;
}a[maxn];
int A[200001], D[200001], isprime[200001];
bool check(int l) {
    int id1 = -1;
    vector<int>w;
    for (int i = 1; i <= n; i ++)
        if (a[i].l <= l) {
            if (a[i].p == 1) {
                if (id1 ==-1 || a[id1].c < a[i].c)
                    id1 = i;
            } else
                w.push_back(i);
        }
    if (id1 != -1)
        w.push_back(id1);
    for (int i = 0; i <=t; i ++)
        e[i].clear();
    s = w.size();
    t = w.size() + 1;
    long long total = 0;
    for (int i = 0; i < w.size(); total += a[w[i]].c, i ++)
        if (a[w[i]].p & 1) {
            addedge(s, i, a[w[i]].c);
            for (int j = 0; j < w.size(); j ++)
                if (isprime[a[w[i]].p + a[w[j]].p])
                    addedge(i, j, inf);
        } else {
            addedge(i, t, a[w[i]].c);
        }
    return total - dinic() >= m;
}
int main() {
    for (int i = 2; i <= 200000; i ++) {
        if (!A[i])
            isprime[D[A[i] =++D[0]] = i]=1;
        for (int j = 1; j <= A[i] && 1ll * i * D[j] <= 200000;j ++)
            A[i * D[j]] = j;
    }
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d %d %d",&a[i].c,&a[i].p, &a[i].l);
    int l = 1, r = n, mid, s = -1;
    while (l <= r) {
        if (check(mid = (l + r) / 2)) {
            r =mid- 1;
            if (s == -1 ||s > mid)
                s = mid;
        } else
            l = mid + 1;
    }
    printf("%d\n", s);
    return 0;
}