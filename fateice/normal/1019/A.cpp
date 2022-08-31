#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,a[3010],b[3010],x[3010],c[3010];
L p=1e18;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	L k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  scanf("%d%d",&a[i],&b[i]);
	for(i=1;i<=n;i++)
	  for(j=i+1;j<=n;j++)
	    if(b[i]>b[j])
	      swap(a[i],a[j]),swap(b[i],b[j]);
	for(i=0;i<=n;i++)
	  {
       k=0;
       for(j=1;j<=m;j++)
         x[j]=0;
       for(j=1;j<=n;j++)
         c[j]=0;
       for(j=n;j>0;j--)
         if(x[a[j]]<i || a[j]==1)
           x[a[j]]++;
         else
           k+=b[j],c[j]=1,x[1]++;
       for(j=1;j<=n;j++)
         if(x[1]<=i && a[j]!=1 && c[j]==0)
           k+=b[j],c[j]=1,x[1]++;
       if(x[1]>i)
         p=min(p,k);
      }
    cout<<p;
	return 0;
}