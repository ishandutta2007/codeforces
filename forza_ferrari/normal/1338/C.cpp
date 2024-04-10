#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int val[]={0,2,3,1};
int t,n,ans;
inline int solve(int k,int lim)
{
    if(lim==1)
        return 1;
    lim>>=2;
    return solve(k-k/lim*lim,lim)+val[k/lim]*lim;
}
inline int calc(int n,int m)
{
    int cnt=0,lim=0;
    while(lim<n)
    {
        lim|=1ll<<cnt;
        cnt+=2;
    }
    cnt-=2;
    lim^=1ll<<cnt;
    if(m==1)
        return (lim<<1)+n;
    if(m==2)
        return 3*lim+(1ll<<cnt)+solve(n-lim-1,1ll<<cnt);
    return ((lim<<1)+n)^(3*lim+(1ll<<cnt)+solve(n-lim-1,1ll<<cnt));
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<calc((n+2)/3,n%3)<<'\n';
    }
    return 0;
}