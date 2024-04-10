#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   long double p=1,n,i;   cin>>n;
    p+=6*(n*(n+1))/2;
     cout<< fixed << setprecision(0)<<p;
    return 0;
}