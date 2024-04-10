#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    float a,b;
    scanf( "%f:%f", &a, &b );
    if( a>=12 )a-=12;
    cout<<(a+(0.5/30)*b)*30<<" "<<b*6;
    return 0;
}