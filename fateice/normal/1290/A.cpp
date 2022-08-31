#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int t,n,m,k,x[5000],p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,l,u;
	scanf("%d",&t);
	while(t--)
	  {
       scanf("%d%d%d",&n,&m,&k);
       for(i=1;i<=n;i++)
         scanf("%d",&x[i]);
       m--;
       k=min(m,k);
       p=0;
       for(i=1;i<=k+1;i++)
         {
          j=i+n-k-1;
          u=1e9+10;
          for(l=0;l<=m-k;l++)
            u=min(u,max(x[i+l],x[j-(m-k-l)]));
          p=max(p,u);
         }
       printf("%d\n",p);
      }
	return 0;
}