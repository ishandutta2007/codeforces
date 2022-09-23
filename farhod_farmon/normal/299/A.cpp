#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a,i;
    cin>>a;
    int b[a+1];
    for( i=1; i<=a; i++ )cin>>b[i];
    sort( b+1, b+a+1 );
    int ans=b[1];
    for( i=2; i<=a; i++ ){
         if( b[i]%b[1]!=0 )ans=-1;
    }
    cout<<ans;
    return 0;    
}