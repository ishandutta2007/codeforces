#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005

using namespace std;
int n,m,i,j,b[N],c[N],x,y,z,deg[N],tot,Ansx[N],Ansy[N],Ansz[N];
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;++i) 
    {
         scanf("%d%d%d",&x,&y,&z);
         b[x]=y; c[x]=z;
         deg[y]++;
    }
    for (i=1;i<=n;++i)
      if (!deg[i]&&c[i])
      {
                  int Min=(int)1e9;
                  for (j=i;b[j];j=b[j]) Min=min(Min,c[j]);
                  ++tot;
                  Ansx[tot]=i; Ansy[tot]=j; Ansz[tot]=Min;
      }
      printf("%d\n",tot);
      for (i=1;i<=tot;++i) printf("%d %d %d\n",Ansx[i],Ansy[i],Ansz[i]);
}