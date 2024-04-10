#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a,b[101],i,j,cnt=0,c=0,d=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
         cin>>b[i];     
         if( b[i]%2!=0 )c++;
    }
    sort( b+1, b+a+1 );
    c=c-(c+1)%2;
    for( i=a; i>=1; i-- ){
         if( c>0 && b[i]%2==0 )cnt+=b[i];    
         if( d<c && b[i]%2!=0 ){
             cnt+=b[i];
             d++;
         }
    }
    cout<<cnt;
    return 0;
}