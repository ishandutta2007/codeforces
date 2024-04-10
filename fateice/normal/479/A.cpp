#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
int a,b,c,d;
int main()
{
    cin>>a>>b>>c;
    d=a+b+c;
    d=max(d,a*b*c);
    d=max(d,a*(b+c));
    d=max(d,a*b+c);
    d=max(d,a+b*c);
    d=max(d,(a+b)*c);
    cout<<d;
    return 0;
}