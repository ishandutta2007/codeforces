#include<iostream>
#include<cstdio>
using namespace std;
int n,m,cnt;
double ans[21],p[21],dp[1<<21];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>p[i];
        if(p[i]>1e-10)
            ++cnt;
    }
    if(cnt<=m)
    {
        for(int i=1;i<=n;++i)
            if(p[i]>1e-10)
                cout<<"1.0 ";
            else
                cout<<"0.0 ";
        cout<<'\n';
        return 0;
    }
    dp[0]=1.000;
    for(int s=0;s<1<<n;++s)
    {
        double val=1.000;
        for(int i=1;i<=n;++i)
            if(s&(1<<(i-1)))
                val-=p[i];
        for(int i=1;i<=n;++i)
            if(p[i]>1e-10&&!(s&(1<<(i-1))))
                dp[s|(1<<(i-1))]+=dp[s]*p[i]/val;
        if(__builtin_popcount(s)==m)
            for(int i=1;i<=n;++i)
                if(s&(1<<(i-1)))
                    ans[i]+=dp[s];
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}