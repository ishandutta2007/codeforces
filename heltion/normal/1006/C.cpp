#include<bits/stdc++.h>
using namespace std;
#define maxn 300000
long long d[maxn], ans;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i += 1) scanf("%lld", d + i), d[i] += d[i - 1];
	for(int i = 1; i < n; i += 1){
		int j = lower_bound(d, d + n + 1, d[n] - d[i]) - d;
		if(d[n] - d[j] == d[i] && j >= i) ans = d[i];
	}
	printf("%lld\n", ans);
}