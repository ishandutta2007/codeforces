#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int f[10];
char c[11];
int main()
{ scanf("%s",&c);
   f[0]=1;
   for (i=1;i<=strlen(c);i++)
   {    if (f[i-1]==1&&c[i-1]=='1') f[i]=1;
        if (i>1&&f[i-2]==1&&c[i-2]=='1'&&c[i-1]=='4') f[i]=1;
        if (i>2&&f[i-3]==1&&c[i-3]=='1'&&c[i-2]=='4'&&c[i-1]=='4') f[i]=1; }
if (f[strlen(c)]==1) printf("YES\n"); else printf("NO\n");
}