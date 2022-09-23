#include <iostream>
using namespace std;
int main()
{
    string s,t;
    char c;
    int i;
    cin>>s;
    c=s[0];
    for( i=1; i<s.size(); i++ ){
         c=max( c, s[i] );     
    }
    for( i=0; i<s.size(); i++ ){
         if( s[i]==c ){
             t+=s[i];    
         }     
    }
    cout<<t;
    return 0;    
}