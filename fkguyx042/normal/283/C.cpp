#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mo=(int)1e9+7;
int fa[3001],size[1001];
int i,j,m,n,p,k,t,q,x,y,flag,num[1001];
int f[100001];
void Do()
{ int i,j;
  for (i=1;i<=q;i++)
  {  for (j=1;j<=n;j++)
       if (fa[j]&&!size[j]) break;
        if (j>n) { printf("0\n");flag=1; return;}
        size[j]--;
        size[fa[j]]--;
        num[fa[j]]+=num[j];
        t-=num[j];
        if (t<0) { printf("0\n");flag=1; return;}
  }
}
void Dp()
{int i,j;
  f[0]=1;
  for (i=1;i<=n;i++)
    for (j=0;j<=t-num[i];j++)
      (f[j+num[i]]+=f[j])%=Mo;
printf("%d\n",f[t]);
}
int main()
{ scanf("%d%d%d",&n,&q,&t);
  for (i=1;i<=n;i++) scanf("%d",&num[i]);
 for (i=1;i<=q;i++) 
 { scanf("%d%d",&x,&y);
   size[y]++; fa[x]=y; 
 }
 Do(); 
 if (!flag) Dp();
}