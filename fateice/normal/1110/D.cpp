#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,x[1000010],f[1000010][3][3],p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l,u,v;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  {
       scanf("%d",&j);
       x[j]++;
      }
    for(i=1;i<=m;i++)
      for(j=0;j<=2;j++)
        for(k=0;k<=2;k++)
          f[i][j][k]=-1e9;
    f[1][0][0]=0;
    for(i=1;i<=m;i++)
      for(j=2;j>=0;j--)
        for(k=2;k>=0;k--)
          if(f[i][j][k]>=0)
            {
             for(l=0;l<=j && l<=x[i];l++)
               for(u=0;u<=k && u+l<=x[i];u++)
                 for(v=0;v<=1 && u+l+v<=x[i];v++)
                   f[i+1][(x[i]-l-u-v)%3][l]=max(f[i+1][(x[i]-l-u-v)%3][l],f[i][j][k]+u+(x[i]-l-u-v)/3);
            }
    for(i=0;i<=2;i++)
      for(j=0;j<=2;j++)
        p=max(p,f[m+1][i][j]);
    cout<<p;
	return 0;
}