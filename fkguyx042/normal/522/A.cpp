#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
using namespace std;
int i,j,m,n,k,fox[1001],ans=1,dis[1001],tot,l,r,Q[100001],vis[1001],k1,pp;
struct Node{int ed,before;}s[100001];
map<string,int>mp;
char c[101],a[101],p[101];
void add(int x,int y)
{s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; }
void spfa(int x)
{memset(dis,0,sizeof(dis)); int i;
  dis[x]=vis[x]=1; Q[1]=x;
  l=r=1;
  for (;l<=r;l++)
  {  pp=Q[l]; ans=max(ans,dis[pp]);
    for (i=fox[pp];i;i=s[i].before)
      if (dis[pp]+1>dis[s[i].ed])
     {  dis[s[i].ed]=dis[pp]+1;
        if (!vis[s[i].ed]) vis[s[i].ed]=1,Q[++r]=s[i].ed;
     }
     vis[pp]=0;
  }
}
int main()
{   
  scanf("%d",&n);
  for (i=1;i<=n;i++)
{  scanf("%s%s%s",&c,&a,&p);
   for (j=0;j<strlen(c);j++) if (c[j]<='Z'&&c[j]>='A') c[j]=c[j]-'A'+'a';
   for (j=0;j<strlen(p);j++) if (p[j]<='Z'&&p[j]>='A') p[j]=p[j]-'A'+'a';
   if (!mp[(string)c]) mp[(string)c]=++tot;
   if (!mp[(string)p]) mp[(string)p]=++tot;
   add(mp[(string)c],mp[(string)p]);
}
   for (i=1;i<=tot;i++) spfa(i);
   printf("%d\n",ans);
}