#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,m;
string a,b;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>a>>b;
        a=" "+a;
        b=" "+b;
        int cnt0=0,cnt1=0;
        for(int i=1;i<=n-m+1;++i)
            if(a[i]=='0')
                ++cnt0;
            else
                ++cnt1;
        bool flag=1;
        if(b[1]=='0')
        {
            if(!cnt0)
                flag=0;
        }
        else
        {
            if(!cnt1)
                flag=0;
        }
        for(int i=2;i<=m;++i)
            if(a[n-m+i]!=b[i])
                flag=0;
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}