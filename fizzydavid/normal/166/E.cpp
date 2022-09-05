#include<iostream>
#include<cstdlib>
#define M 1000000007
using namespace std;
unsigned long long n,ans,a1=1,b1=0,c1=0,d1=0,a2=0,b2=0,c2=0,d2=0,i;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        a2=(b1+c1+d1)%M;
        b2=(a1+c1+d1)%M;
        c2=(a1+b1+d1)%M;
        d2=(a1+b1+c1)%M;
        a1=a2;b1=b2;c1=c2;d1=d2;
    }
    cout<<a1;
    return 0;
}