#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    float a,b,c,d,e,f;
    int n,i;
    cin>>a>>b>>c;
    d=(c*a*b)/100;
    n=d;
    e=a;
    for( i=1; i<=a; i++ ){
         if( n>=int(b) ){
             cout<<b<<" ";
             n-=b;    
         }     
         else{
              cout<<n<<" ";
              n=0;     
         }
    }
    //system( "pause" );
    return 0;
}