#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1000001],b[1000001],block,tag,maxn,bin[1000001],s[1000001],root[1000001],num[1000001];
struct element
{
    int opt,l,r,val,ans;
}q[500001];
namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline long long read()
	{
        bool sign=0; char ch=nc();long long x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return 0;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
        return x;
    }
    #undef BUF_SIZE
};
using namespace fastIO;
inline int Max(register int x,register int y)
{
    return x>y? x:y;
}
inline int Min(register int x,register int y)
{
    return x<y? x:y;
}
inline void print(register int x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
inline int anc(register int k)
{
    return bin[k]==k? k:bin[k]=anc(bin[k]);
}
inline void link(register int x,register int y)
{
    root[y]? bin[root[x]]=root[y]:num[root[y]=root[x]]=y;
    s[y]+=s[x];
    root[x]=s[x]=0;
}
inline void build(register int l,register int r)
{
    maxn=-1<<30;
    tag=0;
    for(register int i=l;i<=r;++i)
    {
        if(root[a[i]])
            bin[i]=root[a[i]];
        else
        {
            root[a[i]]=bin[i]=i;
            num[i]=a[i];
        }
        ++s[a[i]];
        maxn=Max(maxn,a[i]);
    }
}
inline void rebuild(register int l,register int r,register int ql,register int qr,register int val)
{
    for(register int i=l;i<=r;++i)
    {
        a[i]=num[anc(i)];
        root[a[i]]=s[a[i]]=0;
        a[i]-=tag;
    }
    for(register int i=l;i<=r;++i)
        num[i]=0;
    register int tmp=Min(r,qr);
    for(register int i=Max(l,ql);i<=tmp;++i)
        if(a[i]>val)
            a[i]-=val;
    build(l,r);
}
inline void update(register int val)
{
    if(val>maxn)
        return;
    if(val<=(maxn-tag)>>1)
    {
        register int tmp=tag+val;
        for(register int i=tag+1;i<=tmp;++i)
            if(root[i])
                link(i,i+val);
        tag+=val;
    }
    else
    {
        for(register int i=val+tag+1;i<=maxn;++i)
            if(root[i])
                link(i,i-val);
        maxn=min(tag+val,maxn);
    }
}
int main()
{
    n=read(),m=read();
    block=sqrt(n);
    for(register int i=1;i<=n;++i)
        a[i]=read();
    for(register int i=1;i<=m;++i)
        q[i].opt=read(),q[i].l=read(),q[i].r=read(),q[i].val=read();
    register int qwq=ceil(n*1.0/block);
    for(register int i=1;i<=qwq;++i)
    {
        register int l=(i-1)*block+1,r=Min(n,i*block);
        build(l,r);
        for(register int j=1;j<=m;++j)
        {
            if(q[j].l>r||q[j].r<l)
                continue;
            if(q[j].opt==1)
            {    
                if(q[j].l<=l&&q[j].r>=r)
                {
                    update(q[j].val);
                    continue;
                }
                rebuild(l,r,q[j].l,q[j].r,q[j].val);
                continue;
            }
            if(q[j].val+tag>1e5+1)
                continue;
            if(q[j].l<=l&&q[j].r>=r)
            {
                q[j].ans+=s[q[j].val+tag];
                continue;
            }
            register int tmp=Min(r,q[j].r);
            for(register int k=Max(l,q[j].l);k<=tmp;++k)
                q[j].ans+=(num[anc(k)]==q[j].val+tag);
        }
        for(register int i=l;i<=r;++i)
        {
            a[i]=num[anc(i)];
            root[a[i]]=s[a[i]]=0;
        }
        for(register int i=l;i<=r;++i)
            num[i]=0;
    }
    for(register int i=1;i<=m;++i)
        if(q[i].opt==2)
        {
            print(q[i].ans);
            putchar('\n');
        }
    return 0;
}