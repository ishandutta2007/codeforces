#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,a,b,minn[5001][5001],dp[5001];
string s;
inline bool check(int l,int r)
{
    string s1=s.substr(1,l),s2=s.substr(l+1,r-l);
    //cout<<s1<<" "<<s2<<endl;
    return s1.find(s2)!=s1.npos;
}
inline int solve(int p)
{
    int l=1,r=p-1,mid,ans=-1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid,p))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return ans;
}
int main()
{
    cin>>n>>a>>b>>s;
    s=" "+s;
    dp[1]=minn[1][1]=a;
    for(int i=2;i<=n;++i)
    {
        int pos=solve(i);
        minn[i][i]=dp[i]=min(dp[i-1]+a,pos==-1? 1<<30:minn[pos][i-1]+b);
        for(int j=i-1;j>=1;--j)
            minn[j][i]=min(minn[j+1][i],dp[j]);
    }
    cout<<dp[n]<<endl;
    return 0;
}