#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a,cnt=0,i,j,h;
    cin>>a;
    for( i=1; i<=a; i++ ){
         for( j=1; j<=a; j++ ){
              h=sqrt( ( i*i )+( j*j ) );
              if( h+i>j && j+i>h && h+j>i && h<=a && h*h==i*i+j*j ){
                  cnt++;
              }  
         }     
    }
    cout<<cnt/2;
    //system ( "pause" );
    return 0;    
}