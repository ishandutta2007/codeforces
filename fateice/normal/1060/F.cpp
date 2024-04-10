#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[60];
double f[60][60],g[60][60],w[60][60][60][60],p;
vi a[60];
inline void dp(int i,int j)
{
    vi u;
    u.clear();
    x[i]=1;
    for(auto k:a[i])
      if(k!=j)
        {
         dp(k,i);
         x[i]+=x[k];
         u.pb(k);
        }
    if(u.size())
      {
       int k,l,v,a,b,c,d;
       for(k=u.size()-1;k>=0;k--)
         {
          a=u[k];
          if(k==u.size()-1)
            {
             for(l=0;l<=n;l++)
               g[a][l]=f[a][l];
             d=x[a];
            }
          else
            {
             b=u[k+1];
             c=x[a];
             for(l=0;l<=n;l++)
               for(v=0;v<=l;v++)
                 g[a][l]+=w[c+d][l][c][v]*f[a][v]*g[b][l-v];
             d+=c;
            }
         }
       for(k=0;k<=d+1;k++)
         {
          for(l=1;l<=d+1;l++)
            if(l>k)
              f[i][k]+=g[a][l-1]/2;
            else
              f[i][k]+=g[a][k-1];
          f[i][k]/=d+1;
         }
       if(!j)
         p=g[a][0];
      }
    else
      {
       f[i][0]=0.5;
       f[i][1]=1;
      }
}
inline void orz(int t)
{
    int i,j,k;
    for(i=1;i<=n;i++)
      for(j=0;j<=n;j++)
        f[i][j]=g[i][j]=0;
    p=1;
    dp(t,0);
    printf("%.10lf\n",p);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	  {
	   scanf("%d%d",&j,&k);
	   a[j].pb(k);
	   a[k].pb(j);
      }
    for(i=0;i<=n;i++)
      for(j=0;j<=i;j++)
        for(k=0;k<=i;k++)
          if(!i || !j || !k)
            w[i][j][k][0]=1;
          else
            for(l=0;l<=j && l<=k;l++)
              w[i][j][k][l]=((l?k*w[i-1][j-1][k-1][l-1]:0)+(i-k)*w[i-1][j-1][k][l])/i;
    for(i=1;i<=n;i++)
      orz(i);
	return 0;
}