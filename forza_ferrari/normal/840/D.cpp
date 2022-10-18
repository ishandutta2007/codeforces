/*#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<random>
#include<cmath>
using namespace std;
int n,m,tot,a[300001],pos[300001],block,ans[300001],cnt[300001];
struct element
{
    int l,r,k,id;
    bool operator <(const element &other) const
    {
        return pos[l]^pos[other.l]? pos[l]<pos[other.l]:pos[l]&1? r<other.r:r>other.r;
    }
}q[300001];
mt19937 rnd(1145141);
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
inline void print(int x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
int main()
{
    n=read(),m=read();
    block=n/sqrt(m);
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        pos[i]=(i-1)/block+1;
    }
    for(int i=1;i<=m;++i)
        q[i].l=read(),q[i].r=read(),q[i].k=read(),q[i].id=i,ans[i]=-1;
    sort(q+1,q+m+1);
    for(int i=1,l=1,r=0;i<=m;++i)
    {
        for(;r<q[i].r;++r)
            ++cnt[a[r+1]];
        for(;l>q[i].l;--l)
            ++cnt[a[l-1]];
        for(;r>q[i].r;--r)
            --cnt[a[r]];
        for(;l<q[i].l;++l)
            --cnt[a[l]];
        int w=(q[i].r-q[i].l+1)/q[i].k;
        for(int j=1,pos=rnd()%(q[i].r-q[i].l+1)+q[i].l;j<=200;++j,pos=rnd()%(q[i].r-q[i].l+1)+q[i].l)
            if(cnt[a[pos]]>w)
                if(ans[q[i].id]==-1)
                    ans[q[i].id]=a[pos];
                else if(a[pos]<ans[q[i].id])
                    ans[q[i].id]=a[pos];
    }
    for(int i=1;i<=m;++i,putchar('\n'))
        if(ans[i]==-1)
            putchar('-'),putchar('1');
        else
            print(ans[i]);
    return 0;
}