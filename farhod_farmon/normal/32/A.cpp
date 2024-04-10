#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int a,b[1001],i,j,c,cnt=0;
    cin>>a>>c;
    for( i=1; i<=a; i++ )cin>>b[i];
    for( i=1; i<=a; i++ ){
         for( j=1; j<=a; j++ ){
              if( i!=j && abs( b[j]-b[i] )<=c )cnt++;     
         }     
    }
    cout<<cnt;
    return 0;
}