#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
long long ans;
int main()
{  scanf("%d%d%d",&n,&m,&k);
   if (k>(n-1)+(m-1)) printf("-1\n");
else {   if (k<=n-1)
          ans=max(ans,1ll*m*(n/(k+1)));
         else { p=k-(n-1);
           ans=max(ans,1ll*1*(m/(p+1)));
}
    if (k<=m-1)
       ans=max(ans,1ll*n*(m/(k+1)));
        else  { p=k-(m-1);
           ans=max(ans,1ll*1*(n/(p+1)));
    }
    printf("%I64d\n",ans);
}
}