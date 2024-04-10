#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[200001],b[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=1;i<=n;++i)
            cin>>b[i];
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            if(a[i]>b[i])
            {
                flag=0;
                break;
            }
            if(a[i]==b[i])
                continue;
            if(b[i]>b[i%n+1]+1)
            {
                flag=0;
                break;
            }
        }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}