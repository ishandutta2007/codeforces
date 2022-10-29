#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[27][27],i,j,m,n,p,k;
char c[11];
int main()
{  scanf("%d",&n);
   for (i=1;i<=n;i++) 
{  scanf("%s",&c);
   int l=c[0]-'a';
   int r=c[strlen(c)-1]-'a';
   int len=strlen(c);
   for (j=0;j<26;j++)
     if (f[j][l]) f[j][r]=max(f[j][r],f[j][l]+len);
    f[l][r]=max(f[l][r],len);
} int ans=0;
 for (i=0;i<26;i++) ans=max(ans,f[i][i]);
 printf("%d\n",ans);
}