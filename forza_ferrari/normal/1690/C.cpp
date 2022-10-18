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
        int now=0;
        for(int i=1;i<=n;++i)
        {
            cin>>b[i];
            if(now<=a[i])
            {
                cout<<b[i]-a[i]<<' ';
                now=b[i];
            }
            else
            {
                cout<<b[i]-now<<' ';
                now=b[i];
            }
        }
        cout<<'\n';
    }
    return 0;
}