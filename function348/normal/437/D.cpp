#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=100010;
struct Edge{int y,ne;};
int a[N],id[N],fa[N],size[N];
Edge e[N*2];int last[N];
int n,m,num;
LL res;
void add(int x,int y)
{
    e[++num].y=y;e[num].ne=last[x];last[x]=num;
}
int find(int i){return fa[i]==i?i:fa[i]=find(fa[i]);}
int cmp(int i,int j){return a[i]>a[j];}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=m;i++) 
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    for (int i=1;i<=n;i++) id[i]=i;
    sort(id+1,id+1+n,cmp);
    for (int i=1;i<=n;i++)
    {
        LL suma=0,sumb=0;
        size[id[i]]=1;
        int l=find(id[i]);
        for (int j=last[id[i]];j;j=e[j].ne)
        {
            int k=find(e[j].y);
            if (k==l)continue;
            if (!size[k])continue;
            fa[k]=l;size[l]+=size[k];
            suma+=1LL*size[k]*size[k];
            sumb+=size[k];
        }
        res=res+(sumb*sumb-suma+sumb*2)*a[id[i]];
    }
    printf("%.6lf\n",res*1.0/n/(n-1));
    return 0;
}