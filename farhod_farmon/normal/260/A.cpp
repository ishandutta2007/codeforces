#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdlib>

#define pb push_back

using namespace std;
int main()
{
    int a,b,c,i;
    cin>>a>>b>>c;
    for( i=0; i<=9; i++ ){
         if( ( a*10+i )%b==0 ){
             cout<<a<<i;
             for( int j=1; j<=c-1; j++ ){
                  cout<<0;     
             }
             return 0;
         }     
    } 
    cout<<-1;
    return 0;    
}