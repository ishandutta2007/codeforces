#include<iostream>
#include<cstdio>
using namespace std;
int t,n,maxn;
int main()
{
    cin>>t;
    while(t--)
    {
        int ans=1;
        cin>>n>>maxn;
        for(int i=2;i<=n;++i)
        {
            int x;
            cin>>x;
            if(x>maxn)
            {
                maxn=x;
                ans=i;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}