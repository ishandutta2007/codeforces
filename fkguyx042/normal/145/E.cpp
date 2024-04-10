#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define maxn 1000100
#define mid ((t[p].l+t[p].r)>>1)
#define ls (p<<1)
#define rs (ls|1)
using namespace std;
struct tree
{
    int l,r;
    int len4[2],len7[2],len47[2];
    int rev;
}t[maxn<<2];
int a[maxn];
int max(int a,int b)
{
    return a>b?a:b;
}
void pushup(int p,int c)
{
    t[p].len4[c]=t[ls].len4[c]+t[rs].len4[c];
    t[p].len7[c]=t[ls].len7[c]+t[rs].len7[c];
    int tmp=t[ls].len4[c]+max(t[rs].len7[c],t[rs].len47[c]);
    t[p].len47[c]=max(tmp,t[ls].len47[c]+t[rs].len7[c]);
}
void change(int p)
{
    t[p].rev^=1;
    swap(t[p].len4[0],t[p].len4[1]);
    swap(t[p].len7[0],t[p].len7[1]);
    swap(t[p].len47[0],t[p].len47[1]);
}
void pushdown(int p)
{
    if(t[p].rev)
    {
        change(ls);
        change(rs);
        t[p].rev=0;
    }
}
void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r,t[p].rev=0;
    if(l==r)
    {
        if(a[l])
        {
            t[p].len7[0]=t[p].len4[1]=1;
            t[p].len7[1]=t[p].len4[0]=0;
        }
        else
        {
            t[p].len7[0]=t[p].len4[1]=0;
            t[p].len7[1]=t[p].len4[0]=1;
        }
        t[p].len47[0]=t[p].len47[1]=0;
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p,0);
    pushup(p,1);
}
int get(int p,int x)
{
    if(t[p].l==t[p].r)
    {
        if(t[p].len4[0])
        return 0;
        return 1;
    }
    pushdown(p);
    if(x>mid)
    return get(rs,x);
    return get(ls,x);
}
void reverse(int p,int l,int r)
{
    if(t[p].l==l&&t[p].r==r)
    {
        change(p);
        return;
    }
    pushdown(p);
    if(l>mid)
    reverse(rs,l,r);
    else if(r<=mid)
    reverse(ls,l,r);
    else
    {
        reverse(ls,l,mid);
        reverse(rs,mid+1,r);
    }
    pushup(p,0);
    pushup(p,1);
}
char str[maxn],tmp[10];
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    for(i=1;i<=n;i++)
    {
        if(str[i]=='4')
        a[i]=0;
        else
        a[i]=1;
    }
    build(1,1,n);
    while(m--)
    {
        int l,r;
        scanf("%s",tmp);
        if(tmp[0]=='s')
        {
            scanf("%d%d",&l,&r);
            reverse(1,l,r);
        }
        else
        {
            printf("%d\n",max(t[1].len4[0],max(t[1].len7[0],t[1].len47[0])));
        }
    }
    return 0;
}