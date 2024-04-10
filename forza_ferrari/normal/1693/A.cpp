#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,sum,a[200001];
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        bool flag=1;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        while(n&&!a[n])
            --n;
        if(!n)
        {
            cout<<"YES\n";
            continue;
        }
        for(int i=1;i<=n;++i)
        {
            sum+=a[i];
            if(sum<0)
                flag=0;
            if(sum==0&&i!=n)
                flag=0;
        }
        if(sum)
            flag=0;
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}