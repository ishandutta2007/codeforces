#include <iostream>
using namespace std;
int main()
{
    int a,b,c[2001],d[2002]={},i,j,cnt=0;
    cin>>a>>b;
    cnt=b;
    for( i=1; i<=a; i++ )cin>>c[i];
    for( i=a; i>=1; i-- )d[i]=max( d[i+1], c[i] );
    for( i=1; i<a; i++ ){
         cnt=max( cnt, b%c[i]+(b/c[i])*d[i] );  
    }
    cout<<cnt;
    return 0;
}