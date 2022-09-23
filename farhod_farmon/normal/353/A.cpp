#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,c,d=0,f=0,cnt=0,i;
    cin>>a;
    for( i=1; i<=a; i++ ){
         cin>>b>>c;
         if( b%2!=0 && c%2!=0 ){
             cnt++;    
         }     
         if( b%2!=0 ){
             d++;    
         }
         if( c%2!=0 ){
             f++;    
         }
    }
    if( d%2==0 && f%2==0 ){
         cout<<0;    
    }
    else if( ( d!=cnt || f!=cnt ) && (d+f)%2==0 ){
         cout<<1;     
    }
    else{
         cout<<-1;     
    }
    //system( "pause" );
    return 0;    
}