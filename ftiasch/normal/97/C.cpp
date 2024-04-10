#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 222;

int n;
double p[N];

int main(){
	scanf("%d", &n);
	for(int i = 0; i <= n; ++ i){
		scanf("%lf", p + i);
	}
	double ans = 0.0;
	for(int i = 0; i * 2 <= n; ++ i){
		ans = max(ans, p[i]);
	}
	for(int i = 0; i <= n; ++ i){
		for(int j = 0; j <= n; ++ j){
			int ii = n - 2 * i;
			int jj = n - 2 * j;
			if(ii > 0 && jj < 0){
				ans = max(ans, (p[i] * -jj + p[j] * ii) / (double)(ii - jj));
			}
		}
	}
	printf("%.8f\n", ans);
	return 0;
}