#include <iostream>
#include <string>
using namespace std;
int main ()
{
string s,h;
int i,g,f=0,f1=0;
cin>>s;
g=s.size();

for( i=0; i<g; i++ ){
   if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B'){
      h=h+" ";
      i=i+2;
    }
   else{
      h=h+s[i];
    }
 }

cout<<h;

return 0;
}