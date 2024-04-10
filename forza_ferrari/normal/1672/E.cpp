#include<iostream>
#include<cstdio>
using namespace std;
int n,ans,maxn;
int main()
{
    cin>>n;
    int l=1,r=4500000,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        cout<<"? "<<mid<<endl;
        int x;
        cin>>x;
        if(x==1)
        {
            maxn=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    ans=maxn;
    for(int i=1;i<=n;++i)
    {
        cout<<"? "<<maxn/i<<'\n';
        int x;
        cin>>x;
        if(x)
            ans=min(ans,maxn/i*x);
    }
    cout<<"! "<<ans<<'\n';
    return 0;
}