#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,h,a[1001],ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>h;
        for(register int i=1;i<=n;++i)
            cin>>a[i];
        sort(a+1,a+n+1);
        ans=h/(a[n]+a[n-1])*2;
        h%=(a[n]+a[n-1]);
        if(!h)
            cout<<ans<<endl;
        else
            if(h<=a[n])
                cout<<ans+1<<endl;
            else
                cout<<ans+2<<endl;
    }
    return 0;
}