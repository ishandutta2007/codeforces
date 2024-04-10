#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int vis[101][101];
int main()
{ scanf("%d",&k);
   p=min(k,4);
   k-=4;
   for (i=1;i<=k;i++)
     vis[(i-1)%3+1][(i-1)/3+1]=1;
printf("+------------------------+\n");

for (i=1;i<=4;i++)
{printf("|");   
if (p>=i) printf("O.");else printf("#.");
    if (i!=3)
	 for (j=1;j<=10;j++) printf("%c.",vis[i==4?3:i][j]==1?'O':'#');
	 else printf("......................|\n");
	 if (i==1) printf("|D|)\n");
	 if (i==2) printf("|.|\n");
	 if (i==4) printf("|.|)\n");
}
printf("+------------------------+\n");
}