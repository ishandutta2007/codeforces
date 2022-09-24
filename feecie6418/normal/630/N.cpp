#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double a,b,c;
int main()
{
    cin>>a>>b>>c;
    printf("%.8lf\n%.8lf\n",max((-b+sqrt(b*b-4*a*c))/2/a,(-b-sqrt(b*b-4*a*c))/2/a),min((-b+sqrt(b*b-4*a*c))/2/a,(-b-sqrt(b*b-4*a*c))/2/a));
    return 0;
}