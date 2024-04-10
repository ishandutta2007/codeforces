#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,a[500001],cnt[1000001],minn[500001],maxn[500001];
vector<int> v[1000001];
long long ans;
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
inline void solve(int l,int r)
{
    if(l==r)
    {
        ++ans;
        return;
    }
    int mid=(l+r)>>1;
    solve(l,mid);
    solve(mid+1,r);
    int w1=0,w2=1e9,w3=0,w4=1e9,pos=mid+1;
    for(int i=mid;i>=l;--i)
    {
        w1=max(w1,a[i]);
        w2=min(w2,a[i]);
        while(pos<=r&&w3<=w1&&w4>=w2)
        {
            w3=max(w3,a[pos]);
            w4=min(w4,a[pos]);
            ++pos;
        }
        if(w1%w2==0)
            ans+=pos-mid-2+(w3<=w1&&w4>=w2);
    }
    w1=0,w2=1e9,w3=0,w4=1e9,pos=mid;
    for(int i=mid+1;i<=r;++i)
    {
        w3=max(w3,a[i]);
        w4=min(w4,a[i]);
        while(pos>=l&&w1<w3&&w2>w4)
        {
            w1=max(w1,a[pos]);
            w2=min(w2,a[pos]);
            --pos;
        }
        if(w3%w4==0)
            ans+=mid-pos-1+(w1<w3&&w2>w4);
    }
    minn[mid]=1e9;
    maxn[mid]=0;
    for(int i=mid+1;i<=r;++i)
    {
        minn[i]=min(minn[i-1],a[i]);
        maxn[i]=max(maxn[i-1],a[i]);
    }
    w1=0,w2=1e9;
    int pl=mid+1,pr=mid+1;
    for(int i=mid;i>=l;--i)
    {
        w1=max(w1,a[i]);
        w2=min(w2,a[i]);
        while(pr<=r&&minn[pr]>=w2)
        {
            for(int j:v[maxn[pr]])
                ++cnt[j];
            ++pr;
        }
        while(pl<pr&&maxn[pl]<=w1)
        {
            for(int j:v[maxn[pl]])
                --cnt[j];
            ++pl;
        }
        ans+=cnt[w2];
    }
    for(int i=pl;i<pr;++i)
        for(int j:v[maxn[i]])
            cnt[j]=0;
    minn[mid+1]=1e9;
    maxn[mid+1]=0;
    for(int i=mid;i>=l;--i)
    {
        minn[i]=min(minn[i+1],a[i]);
        maxn[i]=max(maxn[i+1],a[i]);
    }
    w1=0,w2=1e9,pl=mid,pr=mid;
    for(int i=mid+1;i<=r;++i)
    {
        w1=max(w1,a[i]);
        w2=min(w2,a[i]);
        while(pr>=l&&minn[pr]>w2)
        {
            for(int j:v[maxn[pr]])
                ++cnt[j];
            --pr;
        }
        while(pl>pr&&maxn[pl]<w1)
        {
            for(int j:v[maxn[pl]])
                --cnt[j];
            --pl;
        }
        ans+=cnt[w2];
    }
    for(int i=pl;i>pr;--i)
        for(int j:v[maxn[i]])
            cnt[j]=0;
}
int main()
{
    t=read();
    for(int i=1;i<=1e6;++i)
        for(int j=i;j<=1e6;j+=i)
            v[j].emplace_back(i);
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
            a[i]=read();
        ans=0;
        solve(1,n);
        cout<<ans<<'\n';
    }
    return 0;
}