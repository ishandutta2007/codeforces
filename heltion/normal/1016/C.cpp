#include<bits/stdc++.h>
#define maxn 320000
using namespace std;
long long a[maxn], b[maxn];
long long sna[maxn], snb[maxn];
long long sa[maxn], sb[maxn];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i += 1){
		scanf("%lld", a + i);
		sna[i] = sna[i - 1] + i * a[i];
		sa[i] = sa[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i += 1){
		scanf("%lld", b + i);
		snb[i] = snb[i - 1] + i * b[i];
		sb[i] = sb[i - 1] + b[i];
	}
	long long ans = 0;
	long long pans = 0;
	long long nans = 0;
	for(int i = 0; i <= n; i += 1){
		if(i & 1){
			pans += (i - 1) * 2 * a[i];
			pans += ((i - 1) * 2 + 1) * b[i];
		}
		else{
			pans += (i - 1) * 2 * b[i];
			pans += ((i - 1) * 2 + 1) * a[i];
		}
		ans = pans;
		if(i & 1){
			ans += (snb[n] - snb[i]) + (i - 1) * (sb[n] - sb[i]);
			//printf("%lld %lld!\n", (snb[n] - snb[i]), (i - 1) * (sb[n] - sb[i]));
			ans += (2 * n + i) * (sa[n] - sa[i]) - (sna[n] - sna[i]);
			//printf("%lld %lld!\n", (2 * n + i) * (sa[n] - sa[i]), (sna[n] - sna[i]));
		}
		else {
			ans += (sna[n] - sna[i]) + (i - 1) * (sa[n] - sa[i]);
			//printf("%lld %lld!\n", (sna[n] - sna[i]), (i - 1) * (sa[n] - sa[i]));
			ans += (2 * n + i)  * (sb[n] - sb[i]) - (snb[n] - snb[i]);
			//printf("%lld %lld!\n", (2 * n + i) * (sb[n] - sb[i]), (snb[n] - snb[i]));
		}
		//printf("i = %d  pans = %lld ans = %lld\n", i, pans, ans);
		nans = max(nans, ans);
	}
	printf("%lld\n", nans);
}