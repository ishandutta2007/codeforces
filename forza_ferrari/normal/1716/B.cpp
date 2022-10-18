#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<n<<'\n';
        for(int i=n;i>=1;--i)
        {
            for(int j=1;j<i;++j)
                cout<<j<<" ";
            cout<<n<<" ";
            for(int j=i;j<n;++j)
                cout<<j<<" ";
            cout<<'\n';
        }
    }
    return 0;
}