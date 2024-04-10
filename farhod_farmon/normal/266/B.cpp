#include <iostream>
using namespace std;
int main ()
{
 int a,b,i,j,f;
 char c[10000];
 cin>>a>>b;
  for(i = 1; i <= a; i++){
  cin>>c[i];
  }
  for(j = 1; j <= b; j++){

    for(i = 1; i <= a; i++){

      if(c[i]=='B' && c[i+1]=='G' && c[i+2]=='G'){
        f=c[i];

        c[i]=c[i+1];

        c[i+1]=f;

        i=i+1;
        }

        else if(c[i]=='B' && c[i+1]=='G'){

        f=c[i];

        c[i]=c[i+1];

        c[i+1]=f;
        }
      }
    }
   for(i = 1; i <= a; i++){
     cout<<c[i];
     }
 return 0;
}