#include <iostream>
using namespace std;
int main()
{
    long long int a,b,c,i,d;
    bool b1=false;
    cin>>a>>b>>c;
    d=b-( a%b );
    for( i=d; i<=c-a; i+=b ){
        b1=true;
        cout<<i<<" ";
    }
    if( b1==false ){
        cout<<-1;
    }
    return 0;
}