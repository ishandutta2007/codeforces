#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

struct item{
    item(int _l = 0,int _r = 0,int _c = 0,int _num = 0) : l(_l), r(_r), c(_c), num(_num) {};
    int l,r,c,num;
};

vector < vector <int> > g;
int f[2005][2005],cost[2005][2005];
//int q[5000004];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k,s,t,c;
    scanf("%d%d",&n,&k);
    vector <item> v;
    for(int i=0;i<n;++i) {
        scanf("%d%d%d",&s,&t,&c);
        v.push_back(item(s,s+t-1,c,i));
    }
    g.resize(2*n+2);
    for(int i=0;i<n;++i) {
//      g[n].push_back(i);
        f[2*n][2*i]=1;
        f[2*i+1][2*n+1]=1;
        f[2*i][2*i+1]=1;
        cost[2*i][2*i+1]=-v[i].c;
        cost[2*i+1][2*i]=v[i].c;
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if (v[i].r<v[j].l) {
                f[2*i+1][2*j]=1;
//              cost[2*i+1][2*j]=v[j].c;
//              cost[2*j][2*i+1]=-v[j].c;
            }
/*  for(int i=0;i<2*n+2;++i) {
        for(int j=0;j<2*n+2;++j)
            cout << cost[i][j] << " ";
        cout << endl;
    }*/
    int flow=0;
    int d[2005],p[2005],INF=2000000000,N=2*n+2,qs,phi[2005]={0};
    int deg[2005]={0};
    for(int i=0;i<2*n+2;++i)
        for(int j=0;j<2*n+2;++j)
            if (f[i][j]) deg[j]++;
    for(int i=0;i<2*n+2;++i) phi[i]=INF;
    vector <int> q(1,2*n); phi[2*n]=0;
    for(int i=0;i<q.size();++i) {
        for(int j=0;j<2*n+2;++j) {
            if (f[q[i]][j]) {
                phi[j]=min(phi[j],phi[q[i]]+cost[q[i]][j]);
                deg[j]--;
                if (deg[j]==0) q.push_back(j);
            }
        }
    }
    for(int kk=0;kk<k;kk++) {
        for(int i=0;i<2*n+2;++i) d[i]=p[i]=INF;
        qs=0;
//      q[qs++]=2*n;
        d[2*n]=0;
        bool was[2005]={0};
        for(;;) {
            int ind=-1;
            for(int i=0;i<2*n+2;++i)
                if (!was[i]&&d[i]!=INF&&(ind==-1||d[i]<d[ind])) ind=i;
            if (ind==-1) break;
            was[ind]=true;
            for(int j=0;j<2*n+2;++j)
                if (f[ind][j]&&d[ind]+phi[ind]-phi[j]+cost[ind][j]<d[j]) {
                    d[j]=d[ind]+phi[ind]-phi[j]+cost[ind][j];
                    p[j]=ind;
                }
        }
        for(int i=0;i<2*n+2;++i)
                phi[i]+=d[i];
        /*for(int t=0;t<2*n+2;++t) {
            bool ok=false;
            for(int i=0;i<2*n+2;++i)
                for(int j=0;j<2*n+2;++j)
                    if (d[i]!=-INF&&f[i][j]) {
                        if (d[j]<d[i]+cost[i][j]) {
                            d[j]=d[i]+cost[i][j];
                            p[j]=i;
                            ok=true;
                        }
                    }
            if (!ok) break;
        }*/
/*      for(int i=0;i<qs;++i) {
            int v=q[i];
            for(int j=0;j<2*n+2;++j) {
                if (f[v][j]&&d[j]<d[v]+cost[v][j]) {
                    d[j]=d[v]+cost[v][j];
                    p[j]=v;
                    q[qs++]=j;
                }
            }
        }*/
//      if (n==50) cout << clock() << endl;
        if (d[2*n+1]!=INF) {
            flow+=d[2*n+1];
            int cur=2*n+1;
            while(cur!=2*n) {
//              if (n==50) cout << cur << " ";
                int prev=p[cur];
                f[prev][cur]--;
                f[cur][prev]++;
                cur=prev;
            }
//          if (n==50) cout << endl;
        } else break;
//      cout << flow << endl;
    }
//  cout << flow << endl;
    for(int i=0;i<n;++i) {
        if (i) printf(" ");
        if (f[2*i][2*i+1]==0) printf("1");
        else printf("0");
    }
    printf("\n");
    return 0;
}