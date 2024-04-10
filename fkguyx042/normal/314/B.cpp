#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,len;
int f[101],g[101],Div[101],Mod[101],ans;
int syc[101][101];
char c[101],s[101];
int main()
{ scanf("%d%d",&n,&m);
  scanf("%s",&c);
  scanf("%s",&s);
  len=strlen(s);
  int Len=strlen(c);
  for (i=0;i<len;i++)
  {   k=i;
    for (j=0;j<strlen(c);j++)
      if (s[k%len]==c[j]) k++;
    Div[i]=k/len;
    Mod[i]=k%len;
  }
  k=0;
  for (i=0;i<n;i++)
{ ans+=Div[k];
  k=Mod[k];
}
printf("%d\n",ans/m);
}