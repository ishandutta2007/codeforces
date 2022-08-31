#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ntc;
    cin>>ntc;
    while(ntc--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        if((b+a-__gcd(a,b)-1)/min(a,b)>=k) cout<<"REBEL\n";
        else cout<<"OBEY\n";
    }

    return 0;
}