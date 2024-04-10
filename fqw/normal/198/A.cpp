#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int k, b, n, t; cin>>k>>b>>n>>t;
	/*
	   int le=0, ri=n;
	   while(le<ri) {
	   int m=(le+ri)/2;
	   double k1=log((double)(k+b-1))+(double)n*log((double)k);
	   double k2=log((double)k*(double)t-(double)t+(double)b)+(double)m*log((double)k);
	   if(k2+1E-8>k1) ri=m;
	   else le=m+1;
	   }
	   cout<<le<<endl;
	 */
	if(k==1) {
		double v=n-(double)(t-1)/(double)b;
		int m=v; while(m+1E-8<v) ++m;
		cout<<max(0, m)<<endl;
	} else {
		double u1=(double)k+(double)b-1.0;
		double u2=(double)k*(double)t-(double)t+(double)b;
		double ax=log(u1/u2)/log((double)k);
		//printf("u1=%.5lf u2=%.5lf\n", u1, u2);
		int m=(int)(n+ax);
		while(m+1E-8<n+ax) ++m;
		cout<<max(0, m)<<endl;
	}
	return 0;
}