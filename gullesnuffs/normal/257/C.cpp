#include <bits/stdc++.h>

using namespace std;

int x[100005], y[100005];
long double ang[100005];
long double PI = 3.14159265358979L;

int main(){
	int n;
	cin >> n;
	for(int i=0; i < n; ++i)
		scanf("%d%d", x+i, y+i);
	long double Min=2*PI, Max=-2*PI;
	for(int i=0; i < n; ++i){
		ang[i]=atan2(y[i], x[i]);
		Min=min(Min, ang[i]);
		Max=max(Max, ang[i]);
	}
	if(Max-Min < 1e-6L){
		puts("0");
		return 0;
	}
	sort(ang, ang+n);
	long double ans=2*PI;
	for(int i=0; i < n; ++i){
		int j=(i+1)%n;
		long double diff=ang[i]-ang[j];
		if(diff == 0)
			continue;
		while(diff < 0)
			diff += 2*PI;
		ans = min(ans, diff);
	}
	double a=ans*180/PI;
	printf("%.7lf\n", a);
}