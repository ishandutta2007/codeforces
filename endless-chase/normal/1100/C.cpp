#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
double n,r,coef,pi;
int main()
{
	scanf("%lf%lf",&n,&r);
	pi=3.14159265358;
	coef=sin(pi/n);
	printf("%.9lf\n",(coef*r)/(1.00-coef));
	return Accepted;
}