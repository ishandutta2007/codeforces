#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int t,n,a[101],ans;
int main()
{
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=2;i<=n;++i)
            if(a[i]<2*a[1])
                continue;
            else
                ans+=(a[i]+2*a[1]-2)/(2*a[1]-1)-1;
        cout<<ans<<'\n';
    }
    return 0;
}