#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,c1,d1,i=0;
    cin>>a>>b;
    if( b%2!=0 ){
        c1=(b+1)/2;
        d1=c1;    
    }
    else{
         c1=b/2;
         d1=c1+1;     
    }
    c=c1;
    d=d1; 
    while( a>0 ){
          if( c==0 && d==b+1 ){
              c=c1;
              d=d1;
          }
          if( c==d ){
              cout<<c<<endl;  
              c--;
              d++;  
          } 
          else if( i==0 ){
               cout<<c<<endl;
               c--; 
               i=1;    
          }
          else if( i==1 ){
               cout<<d<<endl;
               d++;
               i=0;  
          }
          a--;
    }
    //system ( "pause" );
    return 0;    
}