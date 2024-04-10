#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[51];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool tag=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            tag^=a[i]&1^1;
        }
        cout<<(tag? "errorgorn":"maomao90")<<'\n';
    }
    return 0;
}