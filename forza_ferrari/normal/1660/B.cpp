#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        sort(a+1,a+n+1);
        cout<<((n==1&&a[1]!=1)||a[n]-a[n-1]>1? "NO":"YES")<<'\n';
    }
    return 0;
}