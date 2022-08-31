#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,t,x[200010],f[200010],g[200010],q,l,r;
vi a[200010],b[200010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	  {
       scanf("%d%d",&j,&k);
       a[k].pb(j);
       b[j].pb(k);
      }
    scanf("%d",&t);
    for(i=1;i<=t;i++)
      scanf("%d",&x[i]);
    q=1;
    g[1]=x[t];
    f[x[t]]=1;
    for(i=1;i<=q;i++)
      for(auto j:a[g[i]])
        if(!f[j])
          {
           f[j]=f[g[i]]+1;
           g[++q]=j;
          }
    for(i=1;i<t;i++)
      {
       k=0;
       for(auto j:b[x[i]])
         if(f[j]==f[x[i]]-1)
           k++;
       if(f[x[i+1]]!=f[x[i]]-1)
         l++,r++;
       else if(k>1)
         r++;
      }
    printf("%d %d\n",l,r);
	return 0;
}