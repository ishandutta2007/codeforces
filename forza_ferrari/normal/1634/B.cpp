#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,x,y;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>y;
        x&=1,y&=1;
        while(n--)
        {
            int z;
            cin>>z;
            x^=(z&1);
        }
        cout<<(x==y? "Alice":"Bob")<<endl;
    }
    return 0;
}