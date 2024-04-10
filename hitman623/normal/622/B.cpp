#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{  char t[6],b='0';
   int a,h,m;
   gets(t);
   cin>>a;
   h=(t[0]-48)*10 + t[1] -48 ;
   m=(t[3]-48)*10 + t[4] -48 ;
   m+=a;
   h+=m/60;
   m%=60;
   h%=24;
   if(h/10==0) cout<<0<<h;
   else cout<<h;
   cout<<':';
   if(m/10==0) cout<<0<<m;
   else cout<<m;
    return 0;
}