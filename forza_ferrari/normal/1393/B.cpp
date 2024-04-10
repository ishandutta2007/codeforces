#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=100000;
int n,q,a[100001],ans[100001<<2][3];
inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
inline void push_up(int k)
{
    int l=0,r=0;
    for(register int i=0;i<3;++i)
        if(ans[ls(k)][l]>=ans[rs(k)][r])
            ans[k][i]=ans[ls(k)][l++];
        else
            ans[k][i]=ans[rs(k)][r++];
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        ans[k][0]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
void update(int node,int l,int r,int k,int p)
{
    if(l==r)
    {
        ans[k][0]+=p;
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update(node,l,mid,ls(k),p);
    if(node>mid)
        update(node,mid+1,r,rs(k),p);
    push_up(k);
}
int main()
{
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        ++a[x];
    }
    build(1,1,maxn);
    scanf("%d",&q);
    while(q--)
    {
        char c=getchar();
        while(c!='+'&&c!='-')
            c=getchar();
        int x;
        scanf("%d",&x);
        update(x,1,maxn,1,c=='+'? 1:-1);
        if(ans[1][0]>=8||(ans[1][0]>=6&&ans[1][1]>=2)||(ans[1][0]>=4&&ans[1][1]>=4)||(ans[1][0]>=4&&ans[1][1]>=2&&ans[1][2]>=2))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}