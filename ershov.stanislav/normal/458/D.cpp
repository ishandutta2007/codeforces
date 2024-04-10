#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

int n, m, k;
long double a[100000], ans, b1=1, b2;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> m >> k;
	a[0]=1;
	for (int i=1; i<=min(n*n, k); i++) a[i]=a[i-1]*(k+1-i)/(m+1-i);
	for (int i=0; i<=n; i++, b1*=(double)(n+1-i)/i) {
		b2=1;
		for (int j=0; j<=n; j++, b2*=(double)(n+1-j)/j) {
			ans+=b1*b2*a[n*i+(n-i)*j];
			if (ans>1e99) {
				cout << "1e99";
				return 0;
			}
		}
	}
	cout << fixed << setprecision(20) << ans;
	return 0;
}