#include <iostream>
using namespace std;
int main ()
{
  string a;
  int b,i,c=0;
  cin>>a;
  for( i = 0; i < a.size(); i ++){
    if(a[i] == 'H' || a[i] == 'Q' || a[i] == '9'){
      c++;
      }
    }
    if(c>0){
      cout<<"YES";
      }
      else {
        cout<<"NO";
        }
  return 0;
  }