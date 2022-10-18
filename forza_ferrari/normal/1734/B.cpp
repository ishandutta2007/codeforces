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
        for(int i=1;i<=n;++i,cout<<'\n')
            for(int j=1;j<=i;++j)
                cout<<(j==1||j==i)<<" ";
    }
    return 0;
}