/*input

10 9

*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

long long digits(long long n) {
	long long ret=0;

	while (n > 0) {
		ret+=(n % 10);
		n /= 10;
	}

	return ret;
}

int main () {
	long long n,s;
	cin >> n >> s;
	long long mi=0, ma = n;
	while(mi!=ma){
		long long vi = (mi+ma+1)/2;
		if(vi-digits(vi)>=s){
			ma = vi-1;
		}else{
			mi = vi;
		}
	}

	cout << n-mi;

	return 0;
}