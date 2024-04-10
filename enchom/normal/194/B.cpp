#include <iostream>
using namespace std;

long long GetNOD(long long a,long long b)
{
    long long d,r;
    if (a<b)
    {
        d=a;
        a=b;
        b=d;
    }
    while (b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    long long t;
    long long n;
    long long i,a1,a2,NOD;
    cin>>t;
    for (i=1;i<=t;i++)
    {
        cin>>n;
        if (n%2==0)
        cout<<n*4+1<<endl;
        else
        {
            a1=4*n;
            a2=n+1;
            NOD=GetNOD(a1,a2);
            a1=a1/NOD;
            a2=a2/NOD;
            cout<<a1+1<<endl;
        }
    }
    return 0;
}