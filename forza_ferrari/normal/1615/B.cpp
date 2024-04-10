#include<iostream>
#include<cstdio>
using namespace std;
int t,l,r,sum[200001][21];
int main()
{
    for(int i=1;i<=200000;++i)
        for(int j=0;j<=20;++j)
        {
            sum[i][j]=sum[i-1][j];
            if(!(i&(1<<j)))
                ++sum[i][j];
        }
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        int ans=r-l+1;
        for(int i=0;i<=20;++i)
            ans=min(ans,sum[r][i]-sum[l-1][i]);
        cout<<ans<<endl;
    }
    return 0;
}