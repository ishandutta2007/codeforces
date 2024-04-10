#include <iostream>
using namespace std;
int main()
{
    bool b1[101]={};
    int a,b[101]={},c[101]={},i,j,h=0,k=0,cnt=0,ii,jj;
    char s[101][101];
    cin>>a;
    for( i=1; i<=a; i++ ){
         for( j=1; j<=a; j++ ){
              cin>>s[i][j];     
         }     
    }
    for( i=1; i<=a; i++ ){
         for( j=1; j<=a; j++ ){
              if( s[i][j]=='E' ){
                  b[i]++;    
              }     
              if( s[j][i]=='E' ){
                  c[i]++;    
              }     
         }
    }
    i=1;
    while( i<=a ){
         if( b[i]==a && c[i]==a ){
             cout<<-1;
             return 0;    
         }
         if( b[i]<a ){
             h++;   
         }       
         if( c[i]<a ){
             k++;    
         }
         i++;
    }
    for( i=1; i<=a; i++ ){
         for( j=1; j<=a; j++ ){
              if( h>k ){
                  ii=i;
                  jj=j;  
              }
              else{
                   ii=j;
                   jj=i;     
              }
              if( s[ii][jj]=='.' ){
                  b1[i]=1;
                  break;    
              }
         }     
    }
    i=1;
    while( i<=a ){
           if( b1[i]==0 ){
               cout<<-1;
               return 0;    
           }       
           i++;
    }
    for( i=1; i<=a; i++ ){
         for( j=1; j<=a; j++ ){
              if( h>k ){
                  ii=i;
                  jj=j;  
              }
              else{
                   ii=j;
                   jj=i;     
              }
              if( s[ii][jj]=='.' ){
                  cout<<ii<<" "<<jj<<endl;
                  break;    
              }
         }     
    }
    //system ( "pause" );
    return 0;    
}