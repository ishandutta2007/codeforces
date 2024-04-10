#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
long long a,b,p;
int main()
{
    cin>>a>>b;
    if(a<b)
      swap(a,b);
    while(b>0)
      {
       p+=a/b;
       a%=b;
       swap(a,b);
      }
    cout<<p;
    return 0;
}