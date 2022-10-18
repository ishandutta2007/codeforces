#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi=acos(-1);
int t,n;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        n<<=1;
        double d=0.5/sin(pi/n);
        double a=abs(pi*0.25-2*pi/n*((n/2+1)/4));
        printf("%.10lf\n",2*d*cos(a));
    }
    return 0;
}