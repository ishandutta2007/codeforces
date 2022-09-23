#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[1001],i,j,k,l,cnt=0;
    cin>>a;
    for( i=1; i<=a; i++ )cin>>b[i];
    for( i=1; i<=a; i++ ){
         for( j=i-1; j>=1; j-- )if( b[j+1]<b[j] )break;     
         for( k=i+1; k<=a; k++ )if( b[k-1]<b[k] )break;     
         cnt=max( cnt, abs((j+1)-(k-1))+1 );
    }
    cout<<cnt;
    return 0;
}