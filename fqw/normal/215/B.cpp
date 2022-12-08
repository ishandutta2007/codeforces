#include <iostream>
#include <cstdio>
using namespace std;

const double pi=3.1415926535897932384626;

pair<double, double> o_o() {
	int n, x, y=1<<30, z=-y;
	scanf("%d", &n); for(int i=0; i<n; ++i) {
		scanf("%d", &x);
		if(x<y) y=x;
		if(x>z) z=x;
	}
	return make_pair((double)y, (double)z);
}

int main() {
	double r1=o_o().second;
	double p1=o_o().second;
	double p2=o_o().first;
	int A, B; scanf("%d%d", &A, &B);
	double ratio=(double)A/(double)B;
	double le=0.0, ri=r1;
	for(int tt=0; tt<999; ++tt) {
		double r2=(le+ri)*.5;
		double m2=pi*r2*r2*p2;
		double m1=pi*r1*r1*p1-pi*r2*r2*p1;
		if(m1/m2<ratio) ri=r2;
			else le=r2;
	}
	printf("%.15lf\n", le);
	return 0;
}