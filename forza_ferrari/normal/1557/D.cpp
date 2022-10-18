#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
int sum,n,m,dp[300001<<1],ans[600001<<3],node[600001<<1],tag[600001<<3],cnt;
vector<pair<int,int> > v[300001<<1];
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
    ans[k]=max(ans[ls(k)],ans[rs(k)]);
}
inline void push_down(int k)
{
    if(tag[k])
    {
        ans[ls(k)]=max(ans[ls(k)],tag[k]);
        ans[rs(k)]=max(ans[rs(k)],tag[k]);
        tag[ls(k)]=max(tag[ls(k)],tag[k]);
        tag[rs(k)]=max(tag[rs(k)],tag[k]);
        tag[k]=0;
    }
}
void update(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
    {
        ans[k]=max(ans[k],p);
        tag[k]=max(tag[k],p);
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
int query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return ans[k];
    push_down(k);
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res=max(res,query(nl,nr,l,mid,ls(k)));
    if(nr>mid)
        res=max(res,query(nl,nr,mid+1,r,rs(k)));
    return res;
}
signed main()
{
    n=read(),m=read();
    for(register int i=1;i<=m;++i)
    {
        int l=read(),x=read(),y=read();
        v[l].push_back(make_pair(x,y));
        if(x>y)
            x^=y^=x^=y;
        node[++cnt]=x;
        node[++cnt]=y;
    }
    sort(node+1,node+cnt+1);
    cnt=unique(node+1,node+cnt+1)-node-1;
    for(register int i=1;i<=n;++i)
        for(register int j=0;j<(int)v[i].size();++j)
        {
            v[i][j].first=lower_bound(node+1,node+cnt+1,v[i][j].first)-node;
            v[i][j].second=lower_bound(node+1,node+cnt+1,v[i][j].second)-node;
        }
    for(register int i=1;i<=n;++i)
    {
        for(register int j=0;j<(int)v[i].size();++j)
            dp[i]=max(dp[i],query(v[i][j].first,v[i][j].second,1,cnt,1));
        ++dp[i];
        dp[i]=min(dp[i],n);
        sum=max(sum,dp[i]);
        for(register int j=0;j<(int)v[i].size();++j)
            update(v[i][j].first,v[i][j].second,1,cnt,1,dp[i]);
    }
    printf("%lld\n",max(n-sum,0ll));
    if(sum==n)
        return 0;
    int pos=0,val=1;
    for(register int i=n;i;--i)
        if(dp[i]==sum)
        {
            pos=i;
            break;
        }
        else
            printf("%lld ",i);
    memset(ans,0,sizeof ans);
    memset(tag,0,sizeof tag);
    for(register int i=0;i<(int)v[pos].size();++i)
        update(v[pos][i].first,v[pos][i].second,1,cnt,1,val);
    for(register int i=pos-1;i;--i)
    {
        int tmp=0;
        for(register int j=0;j<(int)v[i].size();++j)
            tmp=max(tmp,query(v[i][j].first,v[i][j].second,1,cnt,1));
        if(tmp==val&&dp[i]==sum-val)
        {
            ++val;
            for(register int j=0;j<(int)v[i].size();++j)
                update(v[i][j].first,v[i][j].second,1,cnt,1,val);
        }
        else
            printf("%lld ",i);
    }
    puts("");
    return 0;
}