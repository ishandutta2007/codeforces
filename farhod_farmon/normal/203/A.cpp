#include <iostream>
using namespace std;
int x,t,a,b,a1,b1;
bool b2=0;
int main()
{
    string s[2]={"NO", "YES"};
    cin>>x>>t>>a>>b>>a1>>b1;
    for( int i=0; i<t; i++ ){
         for( int j=0; j<t; j++ ){
              if( ( a-i*a1 )+( b-j*b1 )==x || a-i*a1==x || b-i*b1==x || x==0 ){
                  b2=1;    
              }     
         }     
    }
    cout<<s[b2];
    //system ( "pause" );
    return 0;    
}