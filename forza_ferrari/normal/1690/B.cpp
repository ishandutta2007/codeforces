#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[50001],b[50001];
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
        int d=-1;
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            if(a[i]<b[i])
            {
                flag=0;
                break;
            }
            if(b[i])
            {
                d=a[i]-b[i];
                break;
            }
        }
        if(d!=-1&&flag)
            for(int i=1;i<=n;++i)
                if(max(0,a[i]-d)!=b[i])
                {
                    flag=0;
                    break;
                }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}