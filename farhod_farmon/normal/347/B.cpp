#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a,b[100001],i,cnt=0,c=0;
    cin>>a;
    for( i=0; i<a; i++ ){
         cin>>b[i];
         if( b[i]==i ){
             cnt++;    
         }     
    }
    for( i=0; i<a; i++ ){
         if( b[i]!=i && b[b[i]]==i ){
             c=1;   
         }     
    }
    if( cnt==a ){
        cout<<a;    
    }
    else{
        cout<<cnt+c+1;     
    }
    return 0;    
}