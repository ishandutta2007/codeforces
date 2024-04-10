#include <bits/stdc++.h>
 
long long div(long long a) {
	long long n=0;
	for (long long i=1; i<=sqrt(a); i++) {
		if (a%i==0) {
			if (i!=sqrt(a)) n+=2;
			else n++;
		}
	}
	return n;
}
 
using namespace std;
int main() {
	long long n, a[399999], gcd_arr;
	cin>>n; for(long long i=0; i<n; i++) cin>>a[i];
	if (n==1) gcd_arr=a[0]; else gcd_arr=__gcd(a[0], a[1]);
	for (long long i=2; i<n; i++) gcd_arr=__gcd(gcd_arr, a[i]);
	cout<<div(gcd_arr);
}