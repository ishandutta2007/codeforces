#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n>m)
            cout<<"NO\n";
        else if(n&1)
        {
            cout<<"YES\n";
            for(int i=1;i<n;++i)
                cout<<"1 ";
            cout<<m-n+1<<'\n';
        }
        else if(m&1)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(int i=1;i<=n-2;++i)
                cout<<"1 ";
            cout<<(m-n+2)/2<<" "<<(m-n+2)/2<<'\n';
        }
    }
    return 0;
}