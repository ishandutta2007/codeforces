#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,k1,x,y,z;
struct Node{int x,before,ed,sum;}s[1000001];
int Que[10000001];
int ans[400001],flow[400001],out[400001],fox[400001];
void add(int x,int y,int z,int X)
{ flow[x]+=z; s[++k1].ed=y; s[k1].before=fox[x]; s[k1].sum=z; s[k1].x=X;fox[x]=k1;}
void Do()
{  Que[++Que[0]]=1;
   flow[1]=0;
  for (int l=1;l<=Que[0];l++)
  {   int p=Que[l];
     for (i=fox[p];i;i=s[i].before)
     {   if (flow[s[i].ed]==out[s[i].ed]&&s[i].ed!=n) continue;
         out[s[i].ed]+=s[i].sum;
         flow[s[i].ed]-=s[i].sum;
         if (flow[s[i].ed]==out[s[i].ed]&&s[i].ed!=n) Que[++Que[0]]=s[i].ed;
         if (s[i].x==s[i].ed) ans[i/2+(i%2!=0)]=1;
    }
}
}
int main()
{scanf("%d%d",&n,&m);
 for (i=1;i<=m;i++)
 {scanf("%d%d%d",&x,&y,&z);
   add(x,y,z,x);
   add(y,x,z,x);
 }
 Do();
 for (i=1;i<=m;i++) printf("%d\n",ans[i]);
}