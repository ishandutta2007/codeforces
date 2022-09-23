#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a,b[101],i;
    cin>>a;
    for( i=1; i<=a; i++ ){
         cin>>b[i];     
    }
    sort( b+1, b+a+1 );
    swap( b[1], b[a] );
    for( i=1; i<=a; i++ ){
         cout<<b[i]<<" ";     
    }
    return 0;    
}