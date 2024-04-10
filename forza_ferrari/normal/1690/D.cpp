#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,m,sum[200001];
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>s;
        s=" "+s;
        int ans=m;
        for(int i=1;i<=n;++i)
        {
            sum[i]=sum[i-1]+(s[i]=='W');
            if(i>=m)
                ans=min(ans,sum[i]-sum[i-m]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}