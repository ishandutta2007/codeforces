#include <iostream>
#include <algorithm>
using namespace std;
int a,b,d,e,f,g,h,i,j,k,cnt=0,ans=0;
int c[3001];

int main()
{
    cin>>a>>b;
    for( i=1; i<=b; i++ ){
         cin>>c[i];     
    }
    sort( c+1, c+b+1 );
    for( i=1; i<b-1; i++ ){
         if( c[i]+1==c[i+1] && c[i+1]+1==c[i+2] ){
             cout<<"NO";
             return 0;
         }     
    }
    if( c[b]==a || c[1]==1 ){
         cout<<"NO";    
    } 
    else{
         cout<<"YES";     
    }
    //system( "pause" );
    return 0;    
}