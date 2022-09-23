#include <iostream>
using namespace std;
int main()
{
    bool b1;
    int a,sum,b[31],c[31],i=1,j,cnt=0;
    cin>>a>>sum;
    for( i=1; i<=a; i++ ){
         cin>>b[i]>>c[i]; 
         cnt+=b[i];    
    }
    while( cnt<sum ){
         b1=false;  
         if( i==a+1 ){
             i=1;    
         }       
         if( b[i]<c[i] ){
             b[i]++;
             cnt++;
         }
         i++;
         for( j=1; j<=a; j++ ){
             if( b[j]<c[j] ){
                 b1=true;    
             }
         }
         if( b1==false ){
             break;    
         }
    }
    if( cnt>sum || cnt<sum ){
        cout<<"NO"; 
        return 0;   
    }
    cout<<"YES\n";
    for( i=1; i<=a; i++ ){
         cout<<b[i]<<" ";     
    }
    //system ( "pause" );
    return 0;    
}