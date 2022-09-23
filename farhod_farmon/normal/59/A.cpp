#include <bits/stdc++.h>
using namespace std;
int main()
{
string s;
int i,small=0,big=0;
cin>>s;
for( i=0; i<s.size(); i++ ){
   if(s[i]>=97){
      small++;
    }
   else{
      big++;
    }
 }
if(big>small){
   for( i=0; i<s.size(); i++ ){
      if(s[i]>=97){
         cout<<char(s[i]-32);
       }
      else{
         cout<<s[i];
       }
    }
}
else{
   for( i=0; i<s.size(); i++ ){
      if(s[i]<97){
         cout<<char(s[i]+32);
       }
      else{
         cout<<s[i];
       }
    }
}
return 0;
}