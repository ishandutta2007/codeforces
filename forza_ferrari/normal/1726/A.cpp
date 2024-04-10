#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[2001],ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(i>1)
                ans=max(ans,a[i-1]-a[i]);
        }
        ans=max(ans,a[n]-a[1]);
        if(n==1)
            cout<<ans<<'\n';
        else
            cout<<max(ans,max(*max_element(a+2,a+n+1)-a[1],a[n]-*min_element(a+1,a+n)))<<'\n';
    }
    return 0;
}