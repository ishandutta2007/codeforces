#include <bits/stdc++.h>

using namespace std;

double PI=3.14159265358F;
double eps=1e-9F;

int main(){
	int n, R, r;
	scanf("%d%d%d", &n, &R, &r);
	bool ans;
	if(n == 1){
		ans= (R >= r);
	}
	else if(n == 2){
		ans = (R >= 2*r);
	}
	else{
		double d=R-r;
		double c=(d*d-2*r*r)/(d*d);
		double v=acos(c);
		ans = ((2*PI/v)-eps >= n);
	}
	puts(ans?"YES":"NO");

}