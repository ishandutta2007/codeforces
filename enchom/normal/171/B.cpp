#include <iostream>
using namespace std;
typedef long long Int;

Int star[18528];

int main()
{
    Int i;
    Int k=1,z=4;
    Int a;
    star[1]=1;
    for (i=2;i<=18527;i++)
    {
        star[i]=( z*(z+1) )/2+3*k;
        k=k+i;
        z=z+3;
    }
    cin>>a;
    cout<<star[a]<<endl;
    return 0;
}