#include<iostream>
#include<fstream>
using namespace std;
typedef long long LL;
LL n,i,p,q,b,g;
LL gcd(LL X,LL Y)
{
    if(!X)return Y;
    if(!Y)return X;
    return gcd(Y,X%Y);
}
int main()
{
    scanf("%I64d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%I64d%I64d%I64d",&p,&q,&b);
        g=gcd(p,q);
        q=q/g;
        g=gcd(q,b);
        while(g!=1)
        {
            q=q/g;
            b=g;
            g=gcd(q,b);
        }
        if(q==1)puts("Finite");
        else puts("Infinite");
    }
    return 0;
}