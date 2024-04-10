#include<bits/stdc++.h>
#define L long long
#define pb push_back
using namespace std;
int n,m,f[300010],g[300010],h[300010],p;
vector<int> a[300010],w;
map<L,int> u;
inline int bfs(int s,int p)
{
    int i,k=0;
    f[s]=1;
    g[1]=s;
    k=1;
    for(i=1;i<=k;i++)
      for(auto j:a[g[i]])
        if(j!=p && !f[j])
          {
           f[j]=f[g[i]]+1;
           h[j]=g[i];
           g[++k]=j;
          }
    return k;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	  {
       scanf("%d%d",&j,&k);
       a[j].pb(k);
       a[k].pb(j);
       u[(L)j*n+k]=u[(L)k*n+j]=1;
      }
    bfs(1,0);
    if(f[n])
      {
       p=f[n]-1;
       for(i=n;i;i=h[i])
         w.pb(i);
      }
    else
      p=100000000;
    for(i=1;i<=n && p>4;i++)
      if(f[i]==3)
          {
           p=4;
           w.clear();
           w.pb(n);
           w.pb(1);
           w.pb(i);
           w.pb(h[i]);
           w.pb(1);
          }
    if(p>5)
      {
       for(i=1;i<=n;i++)
         f[i]=0;
       for(auto i:a[1])
         if(!f[i])
           {
            if(p<=5)
              break;
            k=bfs(i,1);
            for(j=1;j<=k && p>5;j++)
              if(f[g[j]]==3)
                {
                 p=5;
                 w.clear();
                 w.pb(n);
                 w.pb(i);
                 w.pb(g[j]);
                 w.pb(h[g[j]]);
                 w.pb(i);
                 w.pb(1);
                }
            for(j=2;j<k && p>5;j++)
              for(l=j+1;l<=k && p>5;l++)
                if(!u[(L)g[j]*n+g[l]])
                  {
                   p=5;
                   w.clear();
                   w.pb(n);
                   w.pb(g[j]);
                   w.pb(g[l]);
                   w.pb(g[1]);
                   w.pb(g[j]);
                   w.pb(1);
                  }
           }
      }
    if(p==100000000)
      printf("-1\n");
    else
      {
       printf("%d\n",p);
       for(i=p;i>=0;i--)
         printf("%d ",w[i]);
       printf("\n");
      }
	return 0;
}