#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[300001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        cout<<(a[1]<a[n]? "Yes":"No")<<'\n';
    }
    return 0;
}