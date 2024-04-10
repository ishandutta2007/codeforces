#include <bits/stdc++.h>

using namespace std;

int a[1005];

int main(){
	int n, l;
	cin >> n >> l;
	for(int i=0; i < n; ++i)
		cin >> a[i];
	sort(a, a+n);
	double ans=max(a[0], l-a[n-1]);
	for(int i=0; i < n-1; ++i)
		ans=max(ans, (a[i+1]-a[i])/2.0);
	printf("%.6lf\n", ans);
}