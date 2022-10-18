#include<iostream>
#include<cstdio>
using namespace std;
long long t,p1,p2,k;
inline long long gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&p1,&p2,&k);
        if(k==1)
        {
            puts("NO");
            continue;
        }
        if(p1>p2)
            p1^=p2^=p1^=p2;
        int _gcd=gcd(p1,p2);
        p1/=_gcd;
        p2/=_gcd;
        puts((p2+p1-2)/p1<=k-1? "OBEY":"REBEL");
    }
    return 0;
}