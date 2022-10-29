#include <cstring>
#include <cstdio>
using namespace std;
const int inf=1e9;
struct arr
{
        int b,pre,c,w;
};
struct node
{
        int y,c,w,next;
};
int n,m,k,i,j,ans,g,tot,st,ed,tmp,flow,flag,lim;
int v[10000],q[5000000],a[10000],l[1000],sum[1000];
node e[5000000];
arr f[10000];
char s[200][200];
void addedge(int x,int y,int c,int w)
{
        tot++;e[tot].y=y;e[tot].c=c;e[tot].w=w;e[tot].next=a[x];a[x]=tot;
        tot++;e[tot].y=x;e[tot].c=0;e[tot].w=-w;e[tot].next=a[y];a[y]=tot;
}
int find()
{
        int h,t,p,x,y;
        for (i=st;i<=ed;i++)
        {
                f[i].b=-1; f[i].pre=-1; f[i].c=0; f[i].w=inf;
        }
        h=0;t=1;q[1]=st;f[st].c=inf;f[st].w=0;v[st]=1;
        while (h!=t)
        {
                h++; x=q[h]; p=a[x];
                while (p!=-1)
                {
                        y=e[p].y;
                        if (e[p].c>0&&f[x].w+e[p].w<f[y].w)
                        {
                                f[y].w=f[x].w+e[p].w;
                                if (f[x].c<e[p].c) f[y].c=f[x].c; else f[y].c=e[p].c;
                                f[y].b=p; f[y].pre=x;
                                if (!v[y])
                                {
                                        t++;q[t]=y;v[y]=1;
                                }
                        }
                        p=e[p].next;
                }
                v[x]=0;
        }
        if (f[ed].w==inf) return 0;
        p=ed; ans+=f[ed].w*f[ed].c; flow+=f[ed].c;
        while (f[p].b!=-1)
        {
                e[f[p].b].c-=f[ed].c; e[f[p].b^1].c+=f[ed].c; p=f[p].pre;
        }
}
int main()
{
        scanf("%s",s[0]); l[0]=strlen(s[0]);
        scanf("%d",&n); st=0;
        tot=-1; memset(a,-1,sizeof(a));
        for (i=1;i<=n;i++)
        {
                scanf("%s %d",s[i],&lim);
                addedge(st,i,lim,i);
                l[i]=strlen(s[i]);
                sum[i]=sum[i-1]+l[i];
        }
        ed=n+sum[n]+l[0]+1;
        for (i=1;i<=n;i++)
        for (j=n+sum[i-1]+1;j<=n+sum[i];j++)
                addedge(i,j,1,0);
        for (k=1;k<=n;k++)
        for (i=0;i<l[k];i++)
        for (j=0;j<l[0];j++)
        if (s[0][j]==s[k][i]) addedge(n+sum[k-1]+i+1,n+sum[n]+j+1,1,0);

        for (i=1;i<=l[0];i++) addedge(n+sum[n]+i,ed,1,0);
        flow=0;
        while (find())
        {
        }
        if (flow==l[0]) printf("%d\n",ans); else printf("-1\n");
        return 0;
}