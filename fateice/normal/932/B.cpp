#include<bits/stdc++.h>
#define L long long
using namespace std;
int n=1e6,t,l,r,f[1000010],x[1000010][10];
inline int orz(int x)
{
    int p=1;
    while(x)
      {
       if(x%10)
         p*=x%10;
       x/=10;
      }
    return p;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	for(i=1;i<=n;i++)
	  {
	   for(j=0;j<10;j++)
	     x[i][j]=x[i-1][j];
	   f[i]=(i<10?i:f[orz(i)]);
	   x[i][f[i]]++;
      }
	scanf("%d",&t);
	while(t--)
	  {
       scanf("%d%d%d",&l,&r,&i);
       printf("%d\n",x[r][i]-x[l-1][i]);
      }
	return 0;
}