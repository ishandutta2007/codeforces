#include <bits/stdc++.h>
using namespace std;

const double x = sqrt(2.0);

double a[100005], s[100005];

int main(){
	int i,m;
	double r;
	while(scanf("%d%lf", &m, &r) != EOF){
		double ans = 0;
		s[0] = 0;
		a[1] = 2.0 * r;
		a[2] = 2.0 * r + x * r;
		a[3] = 2.0 * r + 2.0 * x * r;
		for (i = 4; i <= m; i++){
			a[i] = a[i - 1] + 2 * r;
		}
		for (i = 1; i <= m; i++){
			s[i] = s[i - 1] + a[i];
		}
		for (i = 1; i <= m; i++){
			ans += (s[i] + s[m - i + 1] - a[1]) / m;
		}
		printf("%.10lf\n", ans / m);
	}
	return 0;
}