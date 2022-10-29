#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
   long double m,n,a,s,t,r;
    cin>>n>>m>>a;
    s=ceil(n/a);
    t=ceil(m/a);
    r=s*t;
    cout<< fixed << setprecision(0)<<s*t;
    return 0;
}