#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,a[200001],ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=30;~i;--i)
        {
            int cnt=0;
            for(int j=1;j<=n;++j)
                cnt+=a[j]>>i&1^1;
            if(cnt<=m)
            {
                m-=cnt;
                ans|=1<<i;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}