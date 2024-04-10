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
        printf("%.10lf\n",1/tan(pi/n));
    }
    return 0;
}