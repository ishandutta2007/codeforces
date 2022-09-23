#include <iostream>
using namespace std;

int farhod(int a, int b)
{
int c,d,i;
c=(b*2)+1;
for( i=0; i<=(a-c)/2; i++ ){
   cout<<"*";
 }
for( i=0; i<=c-3; i++ ){
   cout<<"D";
 }
for( i=0; i<=(a-c)/2; i++ ){
   cout<<"*";
 }
}

int main ()
{
int a,b,i;
cin>>a;
for( i=1; i<=a/2; i++ ){
   farhod(a,i);
   cout<<endl;
 }
for( i=1; i<=a; i++ ){
   cout<<"D";
 }
cout<<endl;
for( i=a/2; i>=1; i-- ){
   farhod(a,i);
   cout<<endl;
 }
}