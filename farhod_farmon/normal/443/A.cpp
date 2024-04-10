#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
int main ()
{
string a;
char s[10000];
int i,j=0,l=0;
getline(cin,a);
for( i=1; i<=a.size(); i=i+3 ){
      l++;
      s[l]=a[i];
 }

sort(s+1, s+l+1);

for(i=1; i<l; i++){
   if(s[i]!=s[i+1]){
      j++;
    }
 }
if(a.size()/3>0){
   cout<<j+1;
   return 0;
 }
cout<<j;
return 0;
}