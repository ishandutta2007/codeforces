#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[100001],cnt;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(a[i]<0)
            {
                ++cnt;
                a[i]=-a[i];
            }
        }
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            if(i<=cnt)
                a[i]=-a[i];
            if(i>1&&a[i]<a[i-1])
            {
                flag=0;
                break;
            }
        }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}