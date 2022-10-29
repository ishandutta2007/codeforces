#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,i,j,p,k;
int main()
 {scanf("%d%d",&n,&m);
   if (n==4&&m==3)
    { printf("0 0\n");
printf("3 0\n");
printf("0 3\n");
printf("1 1\n");
return 0;
}
if (n==3&&m==3) { printf("-1 0\n"); printf("1 0\n"); printf("0 1\n"); return 0; }
if (m==3) {printf("-1\n"); return 0;}
p=2;
//if (m%2==1){printf("0 0\n"); m--; n--;}
for (i=1;i<=m;i++)
 { if (p%2==0) { printf("%d %d\n",p/2,(p/2)*(p/2)+10086);}
 else printf("%d %d\n",-p/2,(p/2)*(p/2)+10086); p++;
}
 p=2;
 for (i=1;i<=n-m;i++)
 { if (p%2==0) { printf("%d %d\n",p/2,-(p/2)*(p/2)-10086);}
 else printf("%d %d\n",-p/2,-((p/2)*(p/2))-10086); p++;
}
return 0;
}