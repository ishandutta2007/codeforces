#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[100001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool flag1=1,flag2=1;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(a[i]==1)
                flag1=0;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<n;++i)
            if(a[i+1]-a[i]==1)
                flag2=0;
        puts(flag1||flag2? "YES":"NO");
    }
    return 0;
}