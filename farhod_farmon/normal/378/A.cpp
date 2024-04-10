#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
using namespace std;
int main ()
{
    int a,b,i,n1=0,n2=0,n3=0;
    cin>>a>>b;
    for(i=1; i<=6; i++)
    {
        if(abs(a-i)<abs(b-i)){n1++;}
        else if(abs(a-i)>abs(b-i)){n3++;}
        else {n2++;}
        }
        cout<<n1<<" "<<n2<<" "<<n3;
    return 0;
}