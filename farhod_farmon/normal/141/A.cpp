#include <iostream>
using namespace std;
int main()
{
string s,s1,s2;
cin>>s>>s1>>s2;
s=s+s1;
int i,d=0,g,f;

g=s.size();

for( i=0; i<g; i++ ){
   for( int j=0; j<g-1; j++ ){
      if(s[j]>s[j+1]){
         f=s[j];
         s[j]=s[j+1];
         s[j+1]=f;
       }
    }
 }

int g1,j;

g1=s2.size();

for( i=0; i<g1; i++ ){
   for( j=0; j<g1-1; j++ ){
      if(s2[j]>s2[j+1]){
         f=s2[j];
         s2[j]=s2[j+1];
         s2[j+1]=f;
       }
    }
 }

if(g1!=g){
   cout<<"NO";
 }

else {
   for( i=0; i<g; i++ ){
      if(s[i]==s2[i]){
         d++;
       }
    }

 if(d==g){
    cout<<"YES";
  }
 else{
    cout<<"NO";
  }
 }

return 0;
}