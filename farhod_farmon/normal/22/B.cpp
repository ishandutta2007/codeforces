#include <iostream>
using namespace std;
int main()
{
    int a,b,i,j,h,k,l=0,m,cnt=0;
    char c[26][26];
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
         for( j=1; j<=b; j++ ){
              cin>>c[i][j];     
         }     
    }
    for( i=1; i<=a; i++ ){
         for( j=1; j<=b; j++ ){
              if( c[i][j]=='0' ){
                  k=j;
                  while( c[i][k+1]=='0' && k<b ){
                         k++;       
                  }
                  bool b1=true;
                  l=i;
                  while( b1==true && l<a ){
                         l++;
                         for( h=j; h<=k; h++ ){
                              if( c[l][h]=='1' ){
                                  b1=false;
                                  l--;
                                  break;    
                              }
                         }                
                  }
                  k=k-j+1;
                  l=l-i+1;
                  cnt=max( cnt, l*2+k*2 );
              }     
         }     
    }
    cout<<cnt;
    return 0;
}