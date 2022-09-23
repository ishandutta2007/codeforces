#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    long long int a,b[100001],d[100001]={},i,j,cnt=0;
    cin>>a;
    for( i=1; i<=a; i++ )cin>>b[i];
    for( i=1; i<=a; i++ ){
         if( b[i]==b[i-1] )d[i]=d[i-1]+1;
         else d[i]=1;     
    }
    for( i=1; i<=a; i++ )cnt+=d[i];
    cout<<cnt;
    return 0;
}