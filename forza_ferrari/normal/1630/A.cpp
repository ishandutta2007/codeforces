#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==n-1)
        {
            if(n<=4)
                puts("-1");
            else
            {
                cout<<n-2<<" "<<n-1<<endl;
                cout<<1<<" "<<3<<endl;
                cout<<0<<" "<<((n-1)^3)<<endl;
                for(int i=1;i<n-1;++i)
                {
                    if(((n-1)^i)<i)
                        continue;
                    if(i==1||i==3||i==0||i==n-2||i==((n-1)^3))
                        continue;
                    cout<<i<<" "<<((n-1)^i)<<endl;
                }
            }
            continue;
        }
        cout<<k<<" "<<n-1<<endl;
        if(k)
            cout<<((n-1)^k)<<" "<<0<<endl;
        for(int i=1;i<n-1;++i)
        {
            if(((n-1)^i)<i)
                continue;
            if(i==k||i==((n-1)^k))
                continue;
            cout<<i<<" "<<((n-1)^i)<<endl;
        }
    }
    return 0;
}