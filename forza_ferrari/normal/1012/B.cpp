#include<iostream>
#include<cstdio>
using namespace std;
int n,m,q,bin[200001<<1],ans;
bool vis[200001<<1];
int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int a,int b)
{
    a=anc(a);
    b=anc(b);
    if(a!=b)
        bin[b]=a;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(register int i=1;i<=q;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        link(x,y+n);
    }
    for(register int i=1;i<=n+m;++i)
        if(!vis[anc(i)])
        {
            ++ans;
            vis[anc(i)]=1;
        }
    printf("%d\n",ans-1);
    return 0;
}