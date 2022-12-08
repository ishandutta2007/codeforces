#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1);
int main() {
	int n;
	double r;
	cin>>n>>r;
	double a=2*PI/n,b=(PI-a)/2;
	double sa=sin(a),sb=sin(b);
	printf("%.8f\n",(sa*r)/(2*sb-sa));
	return 0;
}