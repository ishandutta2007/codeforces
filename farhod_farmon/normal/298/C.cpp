#include <iostream>
using namespace std;
int main()
{
    string s,t;
    int a=0,b=0,i;
    cin>>s>>t;
    for( i=0; i<s.size(); i++ ){
         a+=( s[i]-48 );     
    }
    for( i=0; i<t.size(); i++ ){
         b+=( t[i]-48 );     
    }
    if( a%2!=0 && a+1>=b || a>=b ){
         cout<<"YES";    
    }
    else{
         cout<<"NO";     
    }
    //system ( "pause" );
    return 0;    
}