#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[100001],ans[100001<<2][26];
bool tag[100001<<2][26];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
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
    for(int i=0;i<26;++i)
        ans[k][i]=ans[ls(k)][i]+ans[rs(k)][i];
}
inline void push_down(int k,int l,int r)
{
    int mid=(l+r)>>1;
    for(int i=0;i<26;++i)
        if(tag[k][i])
        {
            for(int j=0;j<26;++j)
                if(i==j)
                {
                    ans[ls(k)][j]=mid-l+1;
                    ans[rs(k)][j]=r-mid;
                    tag[ls(k)][j]=tag[rs(k)][j]=1;
                }
                else
                    ans[ls(k)][j]=ans[rs(k)][j]=tag[ls(k)][j]=tag[rs(k)][j]=0;
            tag[k][i]=0;
            break;
        }
        
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        ans[k][a[l]]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int nl,int nr,int l,int r,int k,int p)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        for(int i=0;i<26;++i)
            if(i==p)
            {
                ans[k][i]=r-l+1;
                tag[k][i]=1;
            }
            else
                ans[k][i]=tag[k][i]=0;
        return;
    }
    push_down(k,l,r);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
inline int query(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
        return ans[k][p];
    push_down(k,l,r);
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res+=query(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        res+=query(nl,nr,mid+1,r,rs(k),p);
    return res;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        char c=getchar();
        while(c<'a'||c>'z')
            c=getchar();
        a[i]=c-'a';
    }
    build(1,1,n);
    while(m--)
    {
        int l=read(),r=read(),tmp[26]={0},root=-1;
        bool flag=1;
        for(int i=0;i<26;++i)
        {
            tmp[i]=query(l,r,1,n,1,i);
            if(tmp[i]&1)
                if(root!=-1)
                    flag=0;
                else
                    root=i;
        }
        if(!flag)
            continue;
        int pos=l;
        for(int i=0;i<26;++i)
        {
            update(pos,pos+(tmp[i]>>1)-1,1,n,1,i);
            pos+=tmp[i]>>1;
        }
        if(root!=-1)
        {
            update(pos,pos,1,n,1,root);
            ++pos;
        }
        for(int i=25;~i;--i)
        {
            update(pos,pos+(tmp[i]>>1)-1,1,n,1,i);
            pos+=tmp[i]>>1;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=0;j<26;++j)
            if(query(i,i,1,n,1,j))
            {
                putchar(j+'a');
                break;
            }
    puts("");
    return 0;
}