#include <bits/stdc++.h>
 
int mod(int a, int n) {
	if (a>=0) return a%n;
	else return ((a+n*(a/n+1))%n);
}
 
 
using namespace std;
int main() {
	int q, n, p[199];
	cin>>q;
	for (int i=1; i<=q; i++) {
		cin>>n; for (int j=0; j<n; j++) cin>>p[j];
		int min=0;
		for (int j=1; j<n; j++) {
			if (p[j]==1) min=j;
		}
		bool c=1;
		if (p[mod((min-1), n)]==2) {
			for (int j=3; j<=n; j++) {
				if (p[mod((min-j+1), n)]!=j) c=0;
			}
		}
		else if (p[mod((min+1), n)]==2) {
			for (int j=3; j<=n; j++) {
				if (p[mod((min+j-1), n)]!=j) c=0;
			}
		}
		else if (n>1) c=0;
		if (c==0) cout << "NO"<<endl; else cout << "YES"<<endl;
	}
}