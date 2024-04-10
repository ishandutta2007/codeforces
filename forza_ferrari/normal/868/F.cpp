#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m,a[100001],dp[21][100001],ans,cnt[100001],l,r;
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
inline void update(int pos,int tag)
{
    ans-=cnt[a[pos]]*(cnt[a[pos]]-1)/2;
    cnt[a[pos]]+=tag;
    ans+=cnt[a[pos]]*(cnt[a[pos]]-1)/2;
}
inline int calc(int nl,int nr)
{
    for(;r<nr;++r)
        update(r+1,1);
    for(;r>nr;--r)
        update(r,-1);
    for(;l<nl;++l)
        update(l,-1);
    for(;l>nl;--l)
        update(l-1,1);
    return ans;
}
inline void solve(int l,int r,int ql,int qr,int tag)
{
    if(l>r||ql>qr)
        return;
    int mid1=0,mid2=(ql+qr)>>1;
    dp[tag][mid2]=1ll<<60;
    for(int i=l;i<=min(r,mid2);++i)
        if(dp[tag][mid2]>dp[tag-1][i]+calc(i+1,mid2))
        {
            dp[tag][mid2]=dp[tag-1][i]+ans;
            mid1=i;
        }
    solve(l,mid1,ql,mid2-1,tag);
    solve(mid1,r,mid2+1,qr,tag);
}
signed main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    l=1;
    for(int i=1;i<=n;++i)
        dp[0][i]=1ll<<60;
    for(int i=1;i<=m;++i)
    {
        dp[i][0]=1ll<<60;
        solve(0,n-1,1,n,i);
        /*for(int j=1;j<=n;++j)
            cout<<dp[i][j]<<" ";
        cout<<endl;*/
    }
    cout<<dp[m][n]<<endl;
    return 0;
}