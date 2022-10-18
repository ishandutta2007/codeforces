#include <cstdio>
#include <algorithm>

double max=0;
double sum[5050]={0};

int main() {
	int n, k; double t;
	scanf("%d %d", &n, &k);
	sum[0]=0;
	for (int i=1;i<=n;++i) {
		scanf("%lf", &t);
		sum[i]=sum[i-1]+t;
		//printf("%.2f", sum[i]);
	} 
	for (int i=k;i<=n;++i) {
		for (int j=1;j+i-1<=n;++j) {
			//printf("%.2f %.2f %d %d\n", sum[j+i-1]-sum[j-1], max, i, j);
			max=std::max(max, (double)(sum[j+i-1]-sum[j-1])/(double)i);
		}
	}printf("%.7f", max);
	return 0;
}