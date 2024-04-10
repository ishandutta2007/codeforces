#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int i,j,m,n,p,k,flag,ans;
int f[2][20020];
int main()
{ scanf("%d",&n);
  for (;n--;i^=1)
  {  scanf("%d",&k);
     memset(f[i],0,sizeof(f[i]));
     for (j=10010-9000;j<=10010+9000;j++) {
        (f[i][j]+=f[i^1][j-k])%=Mo;
        (f[i][j]+=f[i^1][j+k])%=Mo;
}
 f[i][10010+k]++;
 f[i][10010-k]++;
 (ans+=f[i][10010])%=Mo;
}
printf("%d\n",ans);
}