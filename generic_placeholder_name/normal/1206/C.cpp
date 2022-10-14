#include <bits/stdc++.h>

using namespace std;
int main () {
	int n, a[199999];
	cin>>n;
	if (n%2==0) cout<<"NO";
	else {
		cout<<"YES"<<endl;
		int tmp=1;
		for (int i=0; i<n; i++) {
			a[i]=2*i+tmp;
			if (tmp==1) tmp=2; else tmp=1;
		}
		for (int i=0; i<n; i++) {
			if (a[i]%2==0) a[n+i]=a[i]-1; else a[n+i]=a[i]+1;
		}
		for (int i=0; i<2*n; i++) cout << a[i] << " ";
	}
}