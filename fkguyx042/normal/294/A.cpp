#include<cstdio>
#include<algorithm>
using namespace std;
int f[102];
int i,j,m,n,p,k,p1,p2;
int main()
 {scanf("%d",&n);
   for (i=1;i<=n;i++)
    scanf("%d",&f[i]);
    scanf("%d",&m);
    for (i=1;i<=m;i++)
 { scanf("%d%d",&p1,&p2);
    f[p1-1]+=p2-1;
    f[p1+1]+=(f[p1]-p2);
    f[p1]=0;
}
for (i=1;i<=n;i++) printf("%d\n",f[i]);
return 0;
}