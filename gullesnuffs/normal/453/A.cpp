#include <bits/stdc++.h>

using namespace std;

int main(){
	int m, n;
	scanf("%d%d", &m, &n);
	double ans=m;
	for(int i=m-1; i >= 1; --i){
		ans -= pow((i+0.0)/(m+0.0), n);
	}
	printf("%.6lf\n", ans);
}