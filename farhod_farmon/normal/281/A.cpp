#include <iostream>
using namespace std;
int main ()
{
string a;
int i,b=0,g;
cin>>a;
g=a.size();
if(a[0]>91){
  b=a[0]-32; cout<<char(b);
    }
      else{
        cout<<a[0];
          }
for(i=1; i<g; i++){
  cout<<a[i];
  }
return 0;
}