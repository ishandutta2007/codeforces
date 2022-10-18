#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,a,b;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(b==1)
            puts("NO");
        else
        {
            puts("YES");
            printf("%lld %lld %lld\n",a,(b*b-1)*a,a*b*b);
        }
    }
    return 0;
}