#include <iostream>
using namespace std;
int main()
{
    int a,i,b=0,d=0,e=0,f=0,g;
    cin>>a;
    char c[a+1];
    for( i=1; i<=a; i++ ){
         cin>>c[i];
         if( c[i]=='R' && b==0 ){
             b=i;
         }     
         if( c[i]=='R' ){
             f=i;    
         }
         if( c[i]=='L' && d==0 ){
             d=i;    
         }
         if( c[i]=='L' ){
             e=i;    
         }
    }
    if( b!=0 ){
         cout<<b<<" "<<f+1;    
    }
    else{
         cout<<e<<" "<<d-1;     
    }
    //system ( "pause" );
    return 0;    
}