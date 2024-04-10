#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int Q[1000005],R[1000005],ans;
char c[1001],s[1000001];
int main()
{  scanf("%s",&c);
   scanf("%s",&s);
   int now=0,last=0;
   int len=strlen(c),Len=strlen(s);
   int tp=0;
   for (i=0;i<Len;i++)
    if (s[i]==c[tp]) {tp++; if (tp==len) break; }
   for (;i<Len;i++)  Q[i]=1;
  tp=len-1;
  for (i=Len-1;i>=0;i--)
    if (s[i]==c[tp]) { tp--; if (tp==-1) break; }
 for (;i>=0;i--) R[i]=1;
 for (i=0;i<Len;i++)
  if (Q[i]&&R[i+1]) ans++;
  printf("%d\n",ans);
}