#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    cout<<a[2]-a[1]<<" "<<a[n]-a[1]<<'\n';
    for(int i=2;i<n;++i)
        cout<<min(a[i]-a[i-1],a[i+1]-a[i])<<" "<<max(a[i]-a[1],a[n]-a[i])<<'\n';
    cout<<a[n]-a[n-1]<<" "<<a[n]-a[1]<<'\n';
    return 0;
}