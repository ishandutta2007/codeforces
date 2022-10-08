#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,m;
int room[100001]; // status of rooms
vector <int> d[100001]; // which 2 switches is room i connected with
vector <int> nb[200001]; // the graph for 2-SAT
vector <int> revnb[200001];  // +100000 to access the negative of i
vector <int> topsort;
int comp[200001];
bool vis[200001];
int scc=0;
void dfstop(int v)
{
    vis[v]=true;
    int i;
    for(i=0;i<nb[v].size();i++)
    {
        if(!vis[nb[v][i]])
            dfstop(nb[v][i]);
    }
    topsort.push_back(v);
}
void dfs2(int v)
{
    vis[v]=true;
    comp[v]=scc;
    int i;
    for(i=0;i<revnb[v].size();i++)
    {
        if(!vis[revnb[v][i]])
            dfs2(revnb[v][i]);
    }

}
int main()
{
    //freopen("t.txt","r",stdin);

 int i,j,x,p,a,b,br=0;
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
 {
    scanf("%d",&room[i]);
    if(room[i]==1)
        br++;
 }

 for(i=1;i<=m;i++)
 {
     scanf("%d",&x);
     for(j=1;j<=x;j++)
     {
         scanf("%d",&p);
         d[p].push_back(i);
     }
 }
 if(br==n)
 {
     cout<<"YES"<<endl;
     return 0;
 }
 for(i=1;i<=n;i++)
 {
     a=d[i][0];
     b=d[i][1];
     if(room[i]==0)   // xor must be 1
     {
         nb[a].push_back(b+100000);
         nb[a+100000].push_back(b);
         nb[b].push_back(a+100000);
         nb[b+100000].push_back(a);
     }
     else
     {
         //cout<<"("<<a<<";"<<b<<")"<<endl;
         nb[a].push_back(b);
         nb[b].push_back(a);
         nb[a+100000].push_back(b+100000);
         nb[b+100000].push_back(a+100000);
     }
 }
 for (i=1;i<=m;i++)
 {
     if (!vis[i])
     {
         dfstop(i);
     }
 }

 for (i=100001;i<=m+100000;i++)
 {
     if (!vis[i])
     {
         dfstop(i);
     }
 }

 for(i=1;i<=m;i++)
 {
     for(j=0;j<nb[i].size();j++)
        {
            revnb[nb[i][j]].push_back(i);

            //cout<<i<<" - "<<nb[i][j]<<endl;
        }
 }
 for(i=100001;i<=100000+m;i++)
 {
     for(j=0;j<nb[i].size();j++)
        {
            revnb[nb[i][j]].push_back(i);

            //cout<<i<<" - "<<nb[i][j]<<endl;
        }
 }

 for(i=1;i<=200000;i++)
    vis[i]=false;
 for(i=topsort.size()-1;i>=0;i--)
 {
     if(!vis[topsort[i]])
     {
         scc++;
         dfs2(topsort[i]);
     }
 }

 for(i=1;i<=m;i++)
 {
     if(comp[i]==comp[i+100000])
     {
         cout<<"NO"<<endl;
         return 0;
     }
 }
 cout<<"YES"<<endl;
 return 0;
}