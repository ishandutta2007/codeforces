#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int INF=(int)1e9;
int fox[100001],l[1001],r[1001],a[1001],b[1001],c[1001],tot,st,ed,ans,u,v,d,n,m,i,j,p,k;
map<pair<int,int>,int>mp;
struct Node{int ed,before,flow;}s[1000001];
int que[100005],dis[100005],k1=1,Max=(int)1e7;
inline int bfs()
 { int i,j,p,k,l,r;
   memset(dis,-1,sizeof(dis));
    l=r=1;
    dis[st]=0;
   que[1]=st;
   while (l<=r)
    { p=que[l];
      for (i=fox[p];i;i=s[i].before)
        if (s[i].flow>0)
        if (dis[s[i].ed]==-1)
         { 
           que[++r]=s[i].ed;
           dis[s[i].ed]=dis[p]+1;
           }
    l++;
}
 if (dis[ed]==-1) return 0;
 return 1;
}
void add(int p1,int p2,int p3) {s[++k1].ed=p2; s[k1].flow=p3; s[k1].before=fox[p1]; fox[p1]=k1;
  s[++k1].ed=p1; s[k1].flow=0; s[k1].before=fox[p2]; fox[p2]=k1; }
int dfs(int num,int flow)
 {  int i,p;
    int a,nowans=0;
   if (num==ed) return flow;
     for (i=fox[num];i&&flow;i=s[i].before)
       if (s[i].flow>0&&dis[s[i].ed]==dis[num]+1)
        if(a=dfs(s[i].ed,min(s[i].flow,flow)))
         { s[i].flow-=a;
           s[i^1].flow+=a;
           flow-=a;nowans+=a;
           }if (!nowans) dis[num]=(int)1e9;
   return nowans;
}
int maxflow()
{ int i,j;
  int ans=0;
    while (bfs())
    { j=dfs(st,(int)1e9);  while (j) ans+=j,j=dfs(st,(int)1e9); }
  return ans;
}
int main()
{    st=++tot;
     ed=++tot;
	 scanf("%d%d",&n,&m);
	 for (i=1;i<=n;i++)  scanf("%d%d%d",&a[i],&b[i],&c[i]);
	 for (i=1;i<=n;i++)  
	{  
	   int sum=-(int)1e9;
	   scanf("%d%d",&l[i],&r[i]);
	   for (j=l[i];j<=r[i];j++)
      {
      	  sum=max(sum,a[i]*j*j+b[i]*j+c[i]);
      }
       ans+=sum;
       mp[make_pair(i,l[i]-1)]=++tot;
       add(st,tot,INF);
       for (j=l[i];j<=r[i];j++) 
       {
       	mp[make_pair(i,j)]=++tot;
       	add(mp[make_pair(i,j-1)],tot,sum-a[i]*j*j-b[i]*j-c[i]);
       }
       add(tot,ed,INF);
    }
     for (i=1;i<=m;i++)
    {
    	 scanf("%d%d%d",&u,&v,&d);
         for (j=l[u]-1;j<=r[u];j++)
        // if (j-d>r[v]) add(mp[make_pair(u,j)],ed,INF);
        // else 
          if (j-d>=l[v]-1&&j-d<=r[v]) add(mp[make_pair(u,j)],mp[make_pair(v,j-d)],INF);
    }
    printf("%d\n",ans-maxflow());
}