#include<cstdio> 
#include<cstring>
#include<algorithm>
#define Maxn 2000+100
#define Mo 1000000007
using namespace std;
int n,m,b[Maxn][Maxn],fac[10000005],Ans[Maxn],Q[Maxn],f[Maxn][Maxn],w,h,Max,i,j,son[Maxn];
inline bool check(int x,int y)
{
    if (b[x][1]>b[y][1]||b[x][2]>b[y][2])return 0;
    return 1;
}
int power(int x,int y)
{
	  int sum=1;
	  for (;y;y>>=1)
	  {
	  	 if (y&1) sum=1ll*sum*x%Mo;
	  	 x=1ll*x*x%Mo;
	  }
	  return sum;
}
inline int cal(int x,int y)
{
    int t1=0,t2=1;
    int i;
    for (i=1;i<=n;++i)
    {
        t1+=b[y][i]-b[x][i];
        t2=1ll*t2*(fac[b[y][i]-b[x][i]])%Mo;
    }
    t1=fac[t1];
    return 1ll*t1*power(t2,Mo-2)%Mo;
}
int main()
{
	  n=2; scanf("%d%d",&w,&h);
     scanf("%d",&m);
     b[m+1][1]=w-1; b[m+1][2]=h-1; Max=max(w,h);
    Max*=n;
    for (i=1;i<=m;++i)
      for (j=1;j<=n;++j)
	scanf("%d",&b[i][j]),b[i][j]--;
    fac[0]=1;
    for (i=1;i<=Max;++i) fac[i]=1ll*fac[i-1]*i%Mo;
    for (i=0;i<=m;++i)
      for (j=0;j<=m+1;++j)
      if(i!=j) if(check(i,j))f[i][j]=cal(i,j),son[j]++;
    int l;Q[Q[0]=1]=0;Ans[0]=-1;
     for (l=1;l<=Q[0];++l) 
     {
        int x=Q[l];
       for (i=1;i<=m+1;++i)
         if(f[x][i])
          {
            son[i]--;
            Ans[i]-=1ll*Ans[x]*f[x][i]%Mo;
            Ans[i]=(Ans[i]%Mo+Mo)%Mo;
            if(!son[i])Q[++Q[0]]=i;
          }
     }
    printf("%d",Ans[m+1]);
}