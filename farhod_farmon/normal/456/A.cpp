#include <iostream>
using namespace std;
int main()
{
  int a,b[100000],b1[100000],i,g;
  cin>>a;
  for( i=1; i<=a; i++ ){
     cin>>b[i]>>b1[i];
   }

  for(i=1; i<a; i++){
     if(b[i]>b[i+1]){
        g=b[i];
        b[i]=b[i+1];
        b[i+1]=g;
        g=b1[i];
        b1[i]=b1[i+1];
        b1[i+1]=g;
      }
   }
     for(i=1; i<=a; i++){
     if(b[i]<b[i+1] && b1[i]>b1[i+1]){

        cout<<"Happy Alex";
        return 0;
      }
   }
  cout<<"Poor Alex";
  return 0;
}