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
    int a,b,c,d[51],i,cnt=0,f;
    cin>>a>>b>>c;
    for( i=1; i<=a; i++ ){
         cin>>d[i];     
    }
    if( b<=c ){
        cout<<0;
        return 0;    
    }
    sort( d+1, d+a+1 );
    b-=( c-1 );
    i=a;
    while( i>=1 && b>0 ){
        if( b-d[i]>0 ){
            b=b-d[i]+1;    
        }   
        else{
             b-=d[i];     
        }        
        i--;
        cnt++;
    }
    if( b>0 ){
        cout<<-1;    
    }
    else{
         cout<<cnt;     
    }
    //system( "pause" );
    return 0;    
}