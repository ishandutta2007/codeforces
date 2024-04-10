#include<iostream>
#include<cstdio>
using namespace std;
int t,n,ans,len;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=len=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            if(x)
                ++len;
            else
            {
                ans+=(bool)len;
                len=0;
            }
        }
        ans+=(bool)len;
        cout<<min(2,ans)<<'\n';
    }
    return 0;
}