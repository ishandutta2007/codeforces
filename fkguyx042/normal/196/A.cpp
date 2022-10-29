#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
char c[100005],Max[100005];
int main()
{ 
   scanf("%s",&c);
   int len=strlen(c);
   for (i=len-1;i>=0;i--)
     Max[i]=max(Max[i+1],c[i]);
   for (i=0;i<len;i++)
    if (Max[i]==c[i]) printf("%c",c[i]);
}