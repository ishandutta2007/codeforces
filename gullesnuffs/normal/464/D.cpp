#include <bits/stdc++.h>

using namespace std;


double dp[2][100005];
double t0Val[100005];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	bool read=0, write=1;
	int maxCons=1000;
	for(int i=0; i <= n; ++i){
		read^=1;
		write^=1;
		t0Val[i]=dp[read][1];
		for(int t=1; t < maxCons; ++t){
			dp[write][t] = (dp[read][t]*t)/(t+1)+dp[read][t+1]/(t+1)+(t*(t+3))/(2.0*(t+1));
		}
	}
	if(k == 1){
		printf("%.9lf\n", t0Val[n]);
		return 0;
	}
	double ans=0;
	int ex=-n;
	double p=1;
	for(int i=0; i < n; ++i){
		p *= k-1;
		while(p > k){
			p /= k;
			++ex;
		}
		while(p < 1){
			p *= k;
			--ex;
		}
	}
	for(int m=0; m <= n; ++m){
		while(p > k){
			p /= k;
			++ex;
		}
		while(p < 1){
			p *= k;
			--ex;
		}
		ans += p*pow(k+0.0, ex+0.0)*k*t0Val[m];

		p*=(n-m+0.0);
		p/=(m+1);
		p/=k-1;
	}
	printf("%.9lf\n", ans);
}