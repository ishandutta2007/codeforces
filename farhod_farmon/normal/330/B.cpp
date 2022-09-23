#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,f[1001]={},i;
    cin>>a>>b;
    for( i=1; i<=b; i++ ){
         cin>>c>>d;
         f[c]=1;
         f[d]=1;     
    }
    c=1;
    while( f[c]!=0 ){
           c++;       
    }
    cout<<a-1<<endl;
    for( i=1; i<=a; i++ ){
         if( i==c ){
             continue;    
         }     
         cout<<c<<" "<<i<<endl;
    }
    //system ( "pause" );
    return 0;    
}