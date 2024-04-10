#include <iostream>
using namespace std;
int main()
{
    int a,i;
    char c[7]={'R', 'O', 'Y', 'G', 'B', 'I', 'V'},d[4]={'B', 'I', 'V', 'G'};
    cin>>a;
    for( i=0; i<7; i++ )cout<<c[i%7];
    for( i=7; i<a; i++ )cout<<d[i%4];
    return 0;
}