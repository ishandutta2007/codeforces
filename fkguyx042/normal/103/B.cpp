#include<stdio.h>
#define maxm 100005
#define maxn 105
using namespace std;
int next[maxm],last[maxn],to[maxm],e[maxn],q[maxn];
int r,x,y,i,j,k,l,s,m,n,tot;
inline void add(int o,int p)
{
    next[++tot]=last[o];
    last[o]=tot;to[tot]=p;
}
int main()
{
    scanf("%d%d",&n,&m);
    if (n!=m)
    {
        printf("NO");
        return 0;
    }
    for (i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    q[1]=1;
    l=0,r=1;
    e[1]=1;
    while (l<r)
    {
        int k=q[++l];
        for (i=last[k];i;i=next[i])
        if (!e[to[i]])
        {
            e[to[i]]=1;
            q[++r]=to[i];
        }
    }
    if (r!=n)
    printf("NO");
    else
    printf("FHTAGN!");
}