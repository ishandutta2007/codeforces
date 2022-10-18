#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,a[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        int ans=0;
        for(int i=2;i<n;++i)
            ans+=a[i]>a[i-1]+a[i+1];
        cout<<(m==1? (n-1)>>1:ans)<<'\n';
    }
    return 0;
}