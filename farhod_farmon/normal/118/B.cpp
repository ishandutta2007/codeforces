#include <iostream>
using namespace std;
int farhod (int a, int b)
{
int i;
for( i=1; i<=a-b; i++ ){
   cout<<"  ";
 }

for( i=0; i<=b-1; i++ ){
   cout<<i<<" ";
 }

cout<<i;

for( i=b-1; i>=0; i-- ){
   cout<<" "<<i;

 }
cout<<endl;
}

int main ()
{
int a,i;
cin>>a;
for( i=0; i<a; i++ ){
   farhod(a,i);
 }

for( i=a; i>=0; i-- ){
   farhod(a,i);
 }
return 0;
}