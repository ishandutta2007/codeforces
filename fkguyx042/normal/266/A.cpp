#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char c[51],s;
int i,j,n,ans;
int main()
{ scanf("%d",&n);
  scanf("%s",&c); s=c[0];
  for (i=1;i<n;i++)
  if (s==c[i]) ans++; else s=c[i];
printf("%d\n",ans);
}