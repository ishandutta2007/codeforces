#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,x,y;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        int n=(x+y)>>1;
        if(x>y)
            cout<<x+y<<endl;
        else
            cout<<y-n%x<<endl;
    }
    return 0;
}