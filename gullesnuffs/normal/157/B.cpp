#include <bits/stdc++.h>

using namespace std;

double r[105];
double PI=3.14159265358979F;

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i)
		scanf("%lf", r+i);
	sort(r,r+n);
	double ans=0;
	for(int i=0; i < n; ++i)
		if((n-i)%2)
			ans += r[i]*r[i]*PI;
		else
			ans -= r[i]*r[i]*PI;
	printf("%.6lf\n", ans);
}