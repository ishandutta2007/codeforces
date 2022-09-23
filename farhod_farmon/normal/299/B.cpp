#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a,i,b,d=0;
    cin>>a>>b;
    char c[a+1];
    string ans="YES";
    for( i=1; i<=a; i++ )cin>>c[i];
    for( i=1; i<=a; i++ ){
         if( c[i]=='#' )d++;
         else d=0;
         if( d>=b )ans="NO";     
    }
    cout<<ans;
    return 0;    
}