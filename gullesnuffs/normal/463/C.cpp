#include <bits/stdc++.h>

using namespace std;

int a[2005][2005];
long long diag[2005][2005][2];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i)
		for(int j=0; j < n; ++j){
			scanf("%d", a[i]+j);
		}
	for(int i=0; i < n; ++i){
		long long sum=0;
		for(int k=0; i+k < n; ++k)
			sum += a[i+k][k];
		for(int k=0; i+k < n; ++k)
			diag[i+k][k][0]=sum;
		sum=0;
		for(int k=0; i+k < n; ++k)
			sum += a[k][i+k];
		for(int k=0; i+k < n; ++k)
			diag[k][i+k][0]=sum;
	}
	for(int i=0; i < n; ++i){
		long long sum=0;
		for(int k=0; i-k >= 0; ++k)
			sum += a[i-k][k];
		for(int k=0; i-k >= 0; ++k)
			diag[i-k][k][1]=sum;
		sum=0;
		for(int k=0; i+k < n; ++k)
			sum += a[n-1-k][i+k];
		for(int k=0; i+k < n; ++k)
			diag[n-1-k][i+k][1]=sum;
	}
	long long best[2]={-1, -1};
	int p[2][2];
	for(int i=0; i < n; ++i)
		for(int j=0; j < n; ++j){
			long long val=diag[i][j][0]+diag[i][j][1]-a[i][j];
			int m=(i+j)%2;
			if(val > best[m]){
				best[m]=val;
				p[m][0]=i+1;
				p[m][1]=j+1;
			}
		}
	printf("%I64d\n%d %d %d %d\n", best[0]+best[1], p[0][0], p[0][1], p[1][0], p[1][1]);
}