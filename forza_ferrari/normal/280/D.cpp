#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct element
{
    int l,r,val;
    element operator +(const element &other) const
    {
        return {l,other.r,val+other.val};
    }
    element operator *(const int &p) const
    {
        return {l,r,val*p};
    }
    element& operator *=(const int &p)
    {
        val*=p;
        return *this;
    }
    bool operator <(const element &other) const
    {
        return val<other.val;
    }
};
struct query_element
{
    element ans,maxn0,maxn1,sum;
};
int n,m,a[100001];
element maxn[100001<<2][2],minn[100001<<2][2],ans[100001<<2][2],sum[100001<<2];
bool tag[100001<<2];
vector<pair<int,int> > v;
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
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
    sum[k]=sum[ls(k)]+sum[rs(k)];
    ans[k][0]=max(max(ans[ls(k)][0],ans[rs(k)][0]),maxn[ls(k)][1]+maxn[rs(k)][0]);
    ans[k][1]=min(min(ans[ls(k)][1],ans[rs(k)][1]),minn[ls(k)][1]+minn[rs(k)][0]);
    maxn[k][0]=max(maxn[ls(k)][0],sum[ls(k)]+maxn[rs(k)][0]);
    maxn[k][1]=max(maxn[rs(k)][1],maxn[ls(k)][1]+sum[rs(k)]);
    minn[k][0]=min(minn[ls(k)][0],sum[ls(k)]+minn[rs(k)][0]);
    minn[k][1]=min(minn[rs(k)][1],minn[ls(k)][1]+sum[rs(k)]);
}
inline void push_down(int k)
{
    if(tag[k])
    {
        sum[ls(k)]*=-1;
        sum[rs(k)]*=-1;
        swap(ans[ls(k)][0]*=-1,ans[ls(k)][1]*=-1);
        swap(ans[rs(k)][0]*=-1,ans[rs(k)][1]*=-1);
        swap(maxn[ls(k)][0]*=-1,minn[ls(k)][0]*=-1);
        swap(maxn[rs(k)][0]*=-1,minn[rs(k)][0]*=-1);
        swap(maxn[ls(k)][1]*=-1,minn[ls(k)][1]*=-1);
        swap(maxn[rs(k)][1]*=-1,minn[rs(k)][1]*=-1);
        tag[ls(k)]^=1;
        tag[rs(k)]^=1;
        tag[k]=0;
    }
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        sum[k]=maxn[k][0]=maxn[k][1]=ans[k][0]=minn[k][0]=minn[k][1]=ans[k][1]={l,l,a[l]};
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
void update1(int node,int l,int r,int k,int p)
{
    if(l==r)
    {
        sum[k]=maxn[k][0]=maxn[k][1]=ans[k][0]=minn[k][0]=minn[k][1]=ans[k][1]={l,l,p};
        return;
    }
    int mid=(l+r)>>1;
    push_down(k);
    if(node<=mid)
        update1(node,l,mid,ls(k),p);
    else
        update1(node,mid+1,r,rs(k),p);
    push_up(k);
}
void update2(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
    {
        sum[k]*=-1;
        swap(ans[k][0]*=-1,ans[k][1]*=-1);
        swap(maxn[k][0]*=-1,minn[k][0]*=-1);
        swap(maxn[k][1]*=-1,minn[k][1]*=-1);
        tag[k]^=1;
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update2(nl,nr,l,mid,ls(k));
    if(nr>mid)
        update2(nl,nr,mid+1,r,rs(k));
    push_up(k);
}
query_element query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return {ans[k][0],maxn[k][0],maxn[k][1],sum[k]};
    push_down(k);
    int mid=(l+r)>>1;
    if(nr<=mid)
        return query(nl,nr,l,mid,ls(k));
    if(nl>mid)
        return query(nl,nr,mid+1,r,rs(k));
    query_element ql=query(nl,nr,l,mid,ls(k)),qr=query(nl,nr,mid+1,r,rs(k)),res;
    res.sum=ql.sum+qr.sum;
    res.ans=max(max(ql.ans,qr.ans),ql.maxn1+qr.maxn0);
    res.maxn0=max(ql.maxn0,ql.sum+qr.maxn0);
    res.maxn1=max(qr.maxn1,ql.maxn1+qr.sum);
    return res;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    build(1,1,n);
    m=read();
    while(m--)
    {
        int opt=read(),l=read(),r=read();
        if(opt==0)
            update1(l,1,n,1,r);
        if(opt==1)
        {
            int t=read(),res=0;
            v.clear();
            for(int i=1;i<=t;++i)
            {
                query_element tmp=query(l,r,1,n,1);
                if(tmp.ans.val<=0)
                    break;
                res+=tmp.ans.val;
                update2(tmp.ans.l,tmp.ans.r,1,n,1);
                v.push_back({tmp.ans.l,tmp.ans.r});
            }
            printf("%d\n",res);
            for(pair<int,int> i:v)
                update2(i.first,i.second,1,n,1);
        }
    }
    return 0;
}