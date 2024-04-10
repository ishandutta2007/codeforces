#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[100],f[500],g[500],h[500],q,p=1e9;
L a[100010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
       scanf("%lld",&a[i]);
       if(a[i]==0)
         {
          i--;
          n--;
          continue;
         }
       for(j=0;j<63;j++)
         if(a[i]&(1ll<<j))
           x[j]++;
      }
    for(i=0;i<63;i++)
      if(x[i]>=3)
        {
         printf("3\n");
         return 0;
        }
    for(i=1;i<=n;i++)
      {
       for(j=1;j<=n;j++)
         f[j]=-1;
       f[i]=0;
       h[1]=i;
       q=1;
       for(k=1;k<=q;k++)
         for(j=1;j<=n;j++)
           if((a[h[k]]&a[j]) && h[k]!=j)
             if(f[j]==-1)
               f[j]=f[h[k]]+1,g[j]=h[k],h[++q]=j;
             else if(j!=g[h[k]])
               p=min(f[h[k]]+f[j]+1,p);
      }
    if(p<1e8)
      printf("%d\n",p);
    else
      printf("-1\n");
	return 0;
}