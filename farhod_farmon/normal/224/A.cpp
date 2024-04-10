#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int x1,x2,x3,a1,a2,a3;
    cin>>x1>>x2>>x3;
    a1=x1*x2/x3;
    a2=x2*x3/x1;
    a3=x1*x3/x2;
    a1=sqrt(a1);
    a2=sqrt(a2);
    a3=sqrt(a3);
    cout<<a1*4+a2*4+a3*4;
}