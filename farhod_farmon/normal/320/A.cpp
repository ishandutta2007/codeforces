#include <iostream>
using namespace std;
int main ()
{
 string s;
 int i,b=0;
 cin>>s;
 for ( i=0; i<s.size(); i++ ){
    if(s[i]=='1' && s[i+1]=='4' && s[i+2]=='4' ){
       i+=2;
     }
    else if(s[i]=='1' && s[i+1]=='4'){
       i++;
     }
    else if(s[i]!='1'){
       b++;
     }
  }
 if(b>0){
    cout<<"NO";
  }
 else {
    cout<<"YES";
  }
 return 0;
 }