#include <bits/stdc++.h>
#define ll long long
ll k,d,t;
int main(){
	std::cin>>k>>d>>t;
	ll seg=(k+d-1)/d*d;
	double a1=(double)k/t+(double)(seg-k)/(2*t);
	ll t1=(ll)1/a1;
	double rem=1-a1*t1;
	double t0=(double)t1*seg;
//	printf("%.6f\n",rem);
	double t2=0,t3=0;
	if(rem<=(double)k/t)t2=rem*t;
	else {
		//printf("!");
		rem-=(double)k/t;t2=k;
		t3=rem*2*t;
	}printf("%.2f",t0+t2+t3);
	return 0;
}