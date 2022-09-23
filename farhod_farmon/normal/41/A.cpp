#include <iostream>
using namespace std;
int main ()
{
 string a,b, a1[10000],b1[10000];
 int i,g,d=0,f=0;
 cin>>a>>b;
 g=a.size();
 for( i=g; i>=0; i-- ){

     a1[d]=a[i];
     d++;
   }
       d=0;
       for( i=0; i<=g; i++ ){
         b1[d]=b[i];
         d++;
     }
       d=0;
       for(i=0; i<=g; i++){
 d++;
         if(a1[d]==b1[i]){f++;}
         }
           if(f==g){
             cout<<"YES";
             }
             else{
               cout<<"NO";
               }
 return 0;
}