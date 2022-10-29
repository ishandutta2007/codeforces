#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,b,Mo,F[505][505],a[505],ans;
void up(int &x,int y)
{
      x+=y;
      if (x>=Mo) x-=Mo;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&b,&Mo);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    F[0][0]=1%Mo;
    for (i=1;i<=n;++i)
      for (j=0;j<m;++j)
       for (k=0;k<=b-a[i];++k)
       if (F[j][k])
         up(F[j+1][k+a[i]],F[j][k]);
    for (i=0;i<=b;++i) (ans+=F[m][i])%=Mo;
    printf("%d\n",ans);
}