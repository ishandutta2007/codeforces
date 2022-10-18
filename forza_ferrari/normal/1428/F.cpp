#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define int long long
int n,ans[500001<<2],minn[500001<<2][2],cnt[500001<<2],tag[500001<<2][2],sum;
string s;
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
    ans[k]=ans[ls(k)]+ans[rs(k)];
    if(minn[ls(k)][0]==minn[rs(k)][0])
    {
        minn[k][0]=minn[ls(k)][0];
        cnt[k]=cnt[ls(k)]+cnt[rs(k)];
        minn[k][1]=min(minn[ls(k)][1],minn[rs(k)][1]);
    }
    if(minn[ls(k)][0]<minn[rs(k)][0])
    {
        minn[k][0]=minn[ls(k)][0];
        cnt[k]=cnt[ls(k)];
        minn[k][1]=min(minn[ls(k)][1],minn[rs(k)][0]);
    }
    if(minn[ls(k)][0]>minn[rs(k)][0])
    {
        minn[k][0]=minn[rs(k)][0];
        cnt[k]=cnt[rs(k)];
        minn[k][1]=min(minn[ls(k)][0],minn[rs(k)][1]);
    }
}
inline void push_down(int k,int l,int r)
{
    int mid=(l+r)>>1;
    if(tag[k][0])
    {
        ans[ls(k)]+=(mid-l+1)*tag[k][0];
        ans[rs(k)]+=(r-mid)*tag[k][0];
        tag[ls(k)][0]+=tag[k][0];
        tag[rs(k)][0]+=tag[k][0];
        minn[ls(k)][0]+=tag[k][0];
        minn[ls(k)][1]+=tag[k][0];
        minn[rs(k)][0]+=tag[k][0];
        minn[rs(k)][1]+=tag[k][0];
        tag[k][0]=0;
    }
    if(tag[k][1])
    {
        if(tag[k][1]>minn[ls(k)][0]&&tag[k][1]<minn[ls(k)][1])
        {
            ans[ls(k)]+=(tag[k][1]-minn[ls(k)][0])*cnt[ls(k)];
            minn[ls(k)][0]=tag[k][1];
            tag[ls(k)][1]=max(tag[ls(k)][1],tag[k][1]);
        }
        if(tag[k][1]>minn[rs(k)][0]&&tag[k][1]<minn[rs(k)][1])
        {
            ans[rs(k)]+=(tag[k][1]-minn[rs(k)][0])*cnt[rs(k)];
            minn[rs(k)][0]=tag[k][1];
            tag[rs(k)][1]=max(tag[rs(k)][1],tag[k][1]);
        }
        tag[k][1]=0;
    }
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        minn[k][0]=minn[k][1]=1ll<<60;
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
        ans[k]=p;
        cnt[k]=1;
        minn[k][0]=p;
        return;
    }
    push_down(k,l,r);
    int mid=(l+r)>>1;
    if(node<=mid)
        update1(node,l,mid,ls(k),p);
    else
        update1(node,mid+1,r,rs(k),p);
    push_up(k);
}
void update2(int nl,int nr,int l,int r,int k)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        ans[k]+=r-l+1;
        ++minn[k][0];
        ++minn[k][1];
        ++tag[k][0];
        return;
    }
    push_down(k,l,r);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update2(nl,nr,l,mid,ls(k));
    if(nr>mid)
        update2(nl,nr,mid+1,r,rs(k));
    push_up(k);
}
void update3(int nl,int nr,int l,int r,int k,int p)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        if(p<=minn[k][0])
            return;
        if(p>minn[k][0]&&p<minn[k][1])
        {
            ans[k]+=(p-minn[k][0])*cnt[k];
            minn[k][0]=p;
            tag[k][1]=max(tag[k][1],p);
            return;
        }
    }
    push_down(k,l,r);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update3(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update3(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
signed main()
{
    cin>>n>>s;
    s=" "+s;
    build(1,1,n);
    int lst=0,len=0;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='1')
        {
            ++len;
            update1(i,1,n,1,1);
            update2(lst+1,i-1,1,n,1);
            update3(1,lst,1,n,1,len);
        }
        else
        {
            lst=i;
            len=0;
            update1(i,1,n,1,0);
        }
        sum+=ans[1];
    }
    cout<<sum<<endl;
    return 0;
}