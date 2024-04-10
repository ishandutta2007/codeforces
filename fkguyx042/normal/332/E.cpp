#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int seed=31;
long long Hash[4405],hash[501][205];
int i,j,m,n,p,k,Len,len,ans[2001],Ans,f[2005][205],g[2005][205];
char s[1000001],c[205],C;
bool Check(int x[])
{  int i;
   for (i=1;i<=k;i++) if (x[i]!=ans[i]) return x[i]<ans[i];
   return false;
}
long long Got(int i)
{  long long sum=0;
  for (;i<=Len;i+=k)  sum=sum*seed+s[i]-'a'+1;
  return sum;
}
long long gt(int i,int j)
{ long long sum=0;
  for (;i<=len;i+=j) sum=sum*seed+c[i]-'a'+1;
  return sum;
}
void Todo(int x)
{  memset(f,0,sizeof(f)); int i,j,Sum[2001];
   memset(g,0,sizeof(g));
   f[k+1][x+1]=1;
   for (i=k;i;i--)
     for (j=1;j<=x+1;j++)
        if (f[i+1][j]) f[i][j]=1;
        else {
                if (f[i+1][j+1]&&Hash[i]==hash[j][x]) f[i][j]=1,g[i][j]=1;
             }
 if (!f[1][1]) return;
 for (i=1,j=1;i<=k;i++) {
    Sum[i]=g[i][j];
    if (g[i][j]==1) j++;
}
Ans=1;
if (Check(Sum))
  for (i=1;i<=k;i++) ans[i]=Sum[i];
}
int main()
{ ans[1]=2;
 for (C=getchar();C!='\n';C=getchar()) s[++Len]=C;
 for (C=getchar();C!='\n';C=getchar()) c[++len]=C;
 scanf("%d",&k);
 if (len>Len||Len/k>len) printf("0\n");
 else { 
   for (i=1;i<=k;i++)  Hash[i]=Got(i);
    for (i=1;i<=len;i++)
    for (j=1;j<=len;j++)
     hash[i][j]=gt(i,j);
    for (i=1;i<=len;i++)
     Todo(i);
  if (!Ans) printf("0\n");
  else for (i=1;i<=k;i++) printf("%d",ans[i]);
}
}