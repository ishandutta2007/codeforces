#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int n,m,s,a[1<<18];
struct element
{
    int sum;
    vector<int> ans,maxl,maxr;
}ans;
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
inline void solve(int l,int r,int len,element &res)
{
    if(l==r)
    {
        res.ans.emplace_back(max(a[l],0ll));
        res.maxl=res.maxr=res.ans;
        res.sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    element ql,qr;
    solve(l,mid,len>>1,ql);
    solve(mid+1,r,len>>1,qr);
    res.ans.resize(len);
    res.maxl.resize(len);
    res.maxr.resize(len);
    res.sum=ql.sum+qr.sum;
    for(int i=0;i<(len>>1);++i)
    {
        res.ans[i]=max(max(ql.ans[i],qr.ans[i]),ql.maxr[i]+qr.maxl[i]);
        res.maxl[i]=max(ql.maxl[i],ql.sum+qr.maxl[i]);
        res.maxr[i]=max(qr.maxr[i],qr.sum+ql.maxr[i]);
        res.ans[(len>>1)+i]=max(max(ql.ans[i],qr.ans[i]),qr.maxr[i]+ql.maxl[i]);
        res.maxl[(len>>1)+i]=max(qr.maxl[i],qr.sum+ql.maxl[i]);
        res.maxr[(len>>1)+i]=max(ql.maxr[i],ql.sum+qr.maxr[i]);
    }
}
signed main()
{
    n=read();
    for(int i=0;i<1<<n;++i)
        a[i]=read();
    solve(0,(1<<n)-1,1<<n,ans);
    m=read();
    while(m--)
        cout<<ans.ans[s^=1<<read()]<<'\n';
    return 0;
}