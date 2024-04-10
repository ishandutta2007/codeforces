#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[100001];
int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        int sum=1;
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            if(sum<1e9)
                sum=1ll*sum/gcd(sum,i+1)*(i+1);
            if(a[i]%sum==0)
            {
                flag=0;
                break;
            }
        }
        puts(flag? "YES":"NO");
    }
    return 0;
}