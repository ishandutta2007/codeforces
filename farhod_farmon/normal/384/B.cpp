#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdio>

#define pb push_back
#define fi first
#define se second

using namespace std;
int main()
{
    int a,b,c,i,j,d;
    cin>>a>>b>>c;
    for( i=1; i<=a; i++ )for( j=1; j<=a; j++ )cin>>d;
    cout<<b*(b-1)/2<<endl;
    for( i=1; i<b; i++ ){
         for( j=i+1; j<=b; j++ ){
              if( c==0 )cout<<i<<" "<<j<<endl; 
              else cout<<j<<" "<<i<<endl;      
         }    
    }
    return 0;    
}