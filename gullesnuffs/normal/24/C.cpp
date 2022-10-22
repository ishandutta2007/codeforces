#include <bits/stdc++.h>

using namespace std;

int x[100005], y[100005];
long long mx[200005], my[200005];

int main(){
	int n;
	long long j;
	scanf("%d%I64d", &n, &j);
	scanf("%I64d%I64d", mx, my);
	for(int i=0; i < n; ++i){
		scanf("%d%d", x+i, y+i);
	}
	for(int i=1; i <= 2*n; ++i){
		int j=(i-1)%n;
		mx[i]=2*x[j]-mx[i-1];
		my[i]=2*y[j]-my[i-1];
	}
	int k=j%(2*n);
	printf("%I64d %I64d\n", mx[k], my[k]);
}