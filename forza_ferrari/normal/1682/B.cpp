#include<iostream>
#include<cstdio>
using namespace std;
int t,n,ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=(1<<20)-1;
        for(int i=0;i<n;++i)
        {
            int x;
            cin>>x;
            if(i^x)
                ans&=x;
        }
        cout<<ans<<'\n';
    }
    return 0;
}