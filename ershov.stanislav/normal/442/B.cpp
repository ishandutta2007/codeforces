#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<long double> a;
long double ans=0;

int main() {
	cin >> n;
	a.resize(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i]>0.9999999999) {
			cout << 1;
			return 0;
		}
	}
	sort(a.begin(), a.end());
	long double sum1=0, mult1=1;
	for (int i=0; i<=n; i++, mult1*=(1-a[i-1]), sum1+=a[i-1]/(1-a[i-1])) {
		long double sum2=sum1, mult2=mult1;
		for (int j=n; j>=i; j--, sum2+=a[j]/(1-a[j]), mult2*=(1-a[j])) {
			ans=max(ans, sum2*mult2);
		}
	}
	cout << fixed << setprecision(15) << ans;
    return 0;
}