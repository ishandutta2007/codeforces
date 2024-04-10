#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,a,b,c,d;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        if(a*d==b*c)
            cout<<"0\n";
        else if((a*d&&b*c%(a*d)==0)||(b*c&&a*d%(b*c)==0))
            cout<<"1\n";
        else
            cout<<"2\n";
    }
    return 0;
}