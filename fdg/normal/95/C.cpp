#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <map>

#define ll long long

using namespace std;

vector < vector <int> > g,gd;
vector < vector <ll> > dist;
vector <int> T,C;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,x,y,a,b,c;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    x--; y--;
    g.resize(n); gd.resize(n);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        a--; b--;
        g[a].push_back(b);
        gd[a].push_back(c);
        g[b].push_back(a);
        gd[b].push_back(c);
    }
    T.resize(n); C.resize(n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&T[i],&C[i]);
    dist.resize(n,vector <ll>(n,1000000000000000LL));
    for(int w=0;w<n;w++)
    {
        priority_queue < pair<ll,int> > q;
        q.push(make_pair(0,w));
        dist[w][w]=0;
        while(!q.empty())
        {
            pair <ll,int> cur=q.top(); q.pop();
            if (-cur.first!=dist[w][cur.second]) continue;
            for(int i=0;i<g[cur.second].size();i++)
            {
                if (gd[cur.second][i]-cur.first<dist[w][g[cur.second][i]])
                {
                    dist[w][g[cur.second][i]]=gd[cur.second][i]-cur.first;
                    q.push(make_pair(-dist[w][g[cur.second][i]],g[cur.second][i]));
                }
            }
        }
        for(int i=0;i<n;i++)
            if (dist[w][i]>T[w]) dist[w][i]=1000000000000000LL;
            else dist[w][i]=C[w];
    }
    vector <ll> dist1(n,1000000000000000LL);
    for(int i=0;i<n;i++)
        dist1[i]=dist[x][i];
    dist1[x]=0;
    vector <bool> used(n,false);
    used[x]=true;
    for(;;)
    {
        int ind=-1;
        for(int i=0;i<n;i++)
            if (!used[i]&&(dist1[i]!=1000000000000000LL&&(ind==-1||dist1[i]<dist1[ind]))) ind=i;
        if (ind==-1) break;
        used[ind]=true;
        for(int i=0;i<n;i++)
            dist1[i]=min(dist1[i],dist1[ind]+dist[ind][i]);
    }
    if (dist1[y]==1000000000000000LL) printf("-1\n");
    else printf("%I64d\n",dist1[y]);
    return 0;
}