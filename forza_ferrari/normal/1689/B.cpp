#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[1001],ans[1001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            ans[i]=i;
        }
        if(n==1)
        {
            cout<<"-1\n";
            continue;
        }
        for(int i=1;i<n;++i)
            if(a[i]==ans[i])
                swap(ans[i],ans[i+1]);
        if(a[n]==ans[n])
            swap(ans[n-1],ans[n]);
        for(int i=1;i<=n;++i)
            cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}