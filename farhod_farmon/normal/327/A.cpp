#include <iostream>
using namespace std;
int main()
{
int a,b[1001],i,j,mina=0,maxn=0,d1=0,d0=0;
cin>>a;
for( i=1; i<=a; i++ ){
   cin>>b[i];
    d1+=b[i];
 }
for( int h=1; h<=a; h++ ){
   for( i=h; i<=a; i++ ){
   maxn=0;
      for( j=h; j<=i; j++ ){
      if( b[j]==0 )maxn++;

       }
       mina=i-h+1;
       mina-=maxn;
       d0=max( d0,d1-mina+maxn );
    }
 }
 cout<<d0<<endl;
}