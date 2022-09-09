#include<bits/stdc++.h>
#define maxn 320000
#define th 100
using namespace std;
typedef long long LL;
LL a[maxn], s[maxn], p[maxn];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i += 1){
		scanf("%lld", a + i);
		a[i] = __builtin_popcountll(a[i]);
		s[i] = a[i] + s[i - 1];
		p[i] = s[i] % 2 + p[i - 1];
	}
	LL ans = 0;
	for(int i = 1; i <= n; i += 1){
		if(i + th <= n){
			if(s[i - 1] % 2) ans += p[n] - p[i + th - 1];
			else ans += (n - i - th + 1) - (p[n] - p[i + th - 1]);
		}
		LL ma = 0, sum = 0;
		for(int j = i; j - i < th && j <= n; j += 1){ 
			ma = max(ma, a[j]);
			sum += a[j];
			if(sum % 2 == 0 && ma * 2 <= sum) ans += 1;
		}
	}
	printf("%lld", ans);
}