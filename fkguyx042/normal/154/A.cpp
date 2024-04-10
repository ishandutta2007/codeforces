#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char c[100001],s[1001];
int A[27][27];
int f[100001][27],i,j,m,n,p,k,ans;
int main()
{ scanf("%s",&c);
  memset(f,60,sizeof(f));
  f[0][26]=0;
  scanf("%d",&k);
  for (i=1;i<=k;i++)
  { scanf("%s",&s);
    A[s[0]-'a'][s[1]-'a']=A[s[1]-'a'][s[0]-'a']=1;
  }
  int Len=strlen(c);
  for (i=0;i<Len;i++)
   for (j=0;j<27;j++)
    if (f[i][j]<(int)1e9)
    { 
      if (!A[j][c[i]-'a'])
      f[i+1][c[i]-'a']=min(f[i+1][c[i]-'a'],f[i][j]);
      f[i+1][j]=min(f[i+1][j],f[i][j]+1);
    }
    ans=(int)1e9;
  for (i=0;i<27;i++) ans=min(ans,f[Len][i]);
  printf("%d\n",ans);
}