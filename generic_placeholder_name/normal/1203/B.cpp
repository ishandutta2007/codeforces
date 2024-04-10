#include <bits/stdc++.h>
 
using namespace std;
int main() {
	int q, n, a[399], x;
	cin>>q;
	for (int i=1; i<=q; i++) {
		cin >> n;
		for (int j=0; j<4*n; j++) cin>>a[j];
		sort(a, a+4*n);
		bool c=1;
		for (int j=0; j<2*n; j++) {
			if (a[2*j]!=a[2*j+1]) c=0; 
		}
		x=a[0]*a[4*n-2];
		for (int j=1; j<2*n; j++) {
			if (a[2*j]*a[4*n-2-2*j]!=x) c=0;
		}
		if (c==0) cout << "NO" << endl; else cout << "YES" << endl; 
	}
}