#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
using namespace std;
int t,n;
string a,b;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>a;
        b=a;
        sort(b.begin(),b.end());
        int ans=0;
        for(int i=0;i<n;++i)
            ans+=a[i]!=b[i];
        cout<<ans<<'\n';
    }
    return 0;
}