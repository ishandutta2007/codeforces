#include <iostream>
using namespace std;
int main()
{
int a,b,c,d=0,i;
cin>>a>>b;
for( i=1; i<=a; i++ ){
   cin>>c;
   d+=c;
 }
if((a-1)*10+d<=b){
   cout<<((a-1)*10)/5+(b-((a-1)*10+d))/5;
 }
else{
   cout<<-1;
 }
return 0;
}