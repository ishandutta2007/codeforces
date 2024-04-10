#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <cstdlib>
#include <cstring>

#define lli long long int 
#define se second
#define fi first
#define pb push_back

using namespace std;
int main()
{
    double b,c,d,e,cnt=0;int a;
    cin>>a>>b>>c>>d>>e;
    c=( (d-b)*(d-b)+(e-c)*(e-c) );
    b=sqrt(c);
    a*=2;
    if( int(b)==b && int(b)%a==0 )cout<<int(b)/a;
    else cout<<int(b)/a+1;
    //system( "pause" );
    return 0;
}