#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        if((n&1)||n<4)
        {
            cout<<"-1\n";
            continue;
        }
        cout<<n/6+(bool)(n%6)<<" "<<(n>>2)<<'\n';
    }
    return 0;
}