#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[100001],m;
bool flag1,flag2;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        flag1=0;
        flag2=n==1;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            flag1|=a[i]==m;
            flag2|=(i>=2&&a[i]>=m&&a[i-1]>=m)||(i>=3&&a[i]>=m&&a[i-2]>=m);
        }
        cout<<(flag1&&flag2? "Yes":"No")<<'\n';
    }
    return 0;
}