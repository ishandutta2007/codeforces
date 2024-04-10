#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[50001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(register int i=1;i<=n;++i)
            cin>>a[i];
        if(!a[n])
        {
            for(register int i=1;i<=n;++i)
                cout<<i<<" ";
            cout<<n+1<<endl;
            continue;
        }
        if(a[1])
        {
            cout<<n+1<<" ";
            for(register int i=1;i<=n;++i)
                cout<<i<<" ";
            cout<<endl;
            continue;
        }
        bool flag=0;
        for(register int i=2;i<=n;++i)
            if(!a[i-1]&&a[i])
            {
                for(register int j=1;j<i;++j)
                    cout<<j<<" ";
                cout<<n+1<<" ";
                for(register int j=i;j<=n;++j)
                    cout<<j<<" ";
                cout<<endl;
                flag=1;
                break;
            }
        if(!flag)
            puts("-1");
    }
    return 0;
}