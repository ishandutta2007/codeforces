#include <iostream>
using namespace std;
int main()
{
    string s[1001],t[1001],s1[4],ans;
    int a,b,c,d,i,j,h,k,g=0;
    cin>>s1[1]>>s1[2]>>s1[3]>>a;
    for( i=1; i<=a; i++ ){
         cin>>s[i];     
    }
    for( i=1; i<=a; i++ ){
         for( j=0; j<s[i].size(); j++ ){
              if( s[i][j]=='-' || s[i][j]=='_' || s[i][j]==';' )continue;
              if( s[i][j]<97 )s[i][j]+=32;
              t[i]+=s[i][j];     
         }     
    }
    s[1]=s[2]=s[3]="";
    for( i=1; i<=3; i++ ){
         for( j=0; j<s1[i].size(); j++ ){
              if( s1[i][j]=='-' || s1[i][j]=='_' || s1[i][j]==';' )continue;
              if( s1[i][j]<97 )s1[i][j]+=32;
              s[i]+=s1[i][j];     
         }     
    }
    for( i=1; i<=a; i++ ){
         g=0;
         for( j=1; j<=3; j++ ){
              for( h=1; h<=3; h++ ){
                   for( k=1; k<=3; k++ ){
                        if( k!=h && k!=j && h!=j ){
                            ans=s[j];
                            ans+=s[h];
                            ans+=s[k];
                            if( t[i]==ans ){
                                g=1;
                                break;    
                            }    
                        }     
                   }     
              }     
         }     
         if( g==1 ){
              cout<<"ACC\n";    
         }
         else{
              cout<<"WA\n";     
         }
    }
    return 0;
}