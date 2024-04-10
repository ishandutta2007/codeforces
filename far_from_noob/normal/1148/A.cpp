#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    long long countans=c*2;
    if(a>=b+1)countans+=b+b+1;
    else if(b>=a+1)countans+=a+a+1;
    else countans+=a+b;
    cout <<countans  << endl;
    return 0;
}