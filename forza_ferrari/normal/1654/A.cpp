#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[1001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        sort(a+1,a+n+1);
        cout<<a[n-1]+a[n]<<'\n';
    }
    return 0;
}