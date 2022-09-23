#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int a,b[100001],i,j,h,cnt=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
         cin>>b[i];
         cnt+=b[i];     
    }
    if( cnt==a ){
        cout<<"YES";
        return 0;    
    }
    for( i=3; i<=11; i++ ){
         if( a%i!=0 )continue;
         for( j=1; j<=a/i; j++ ){
              cnt=0;
              for( h=j; h<=a; h=h+( a/i ) ){
                   cnt+=b[h];     
              }     
              if( cnt==i ){
                  cout<<"YES";
                  return 0;    
              }
         }     
    }
    cout<<"NO";
    return 0;
}