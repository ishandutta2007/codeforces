#include <bits/stdc++.h>
 
using namespace std;
int main() {
	int n, m, a[100], b[100];
	cin>>n; for(int i=0; i<n; i++) cin>>a[i];
	cin>>m; for(int i=0; i<m; i++) cin>>b[i];
	sort(a, a+n); sort(b, b+m); cout << a[n-1] << " " << b[m-1];
}