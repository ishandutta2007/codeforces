#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
float a,b,c;
cin>>a;
for( int i=1; i<=a; i++ ){
   cin>>b;
   c+=b;
 }
printf("%.12f",c/a);
return 0;
}