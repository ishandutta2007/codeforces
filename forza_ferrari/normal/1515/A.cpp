#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,a[101],sum;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        sum=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum==m)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        sum=0;
        for(int i=1;i<=n;++i)
        {
            sum+=a[i];
            if(sum==m)
                swap(a[i],a[i+1]);
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}