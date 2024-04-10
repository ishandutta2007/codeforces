#include<bits/stdc++.h>
using namespace std;
#define maxn 2000000
long long a[maxn], p2[maxn] = {1};
const long long mod = 998244353;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i += 1){
		scanf("%lld", a + i);
		p2[i] = p2[i - 1] * 2 % mod;
	}
	long long tmp = 0, ans = 0;
	for(int i = 1; i <= n; i += 1){
		tmp = (tmp + a[i - 1] * p2[n - i] % mod) % mod;
		ans = (ans + tmp + a[i] * p2[n - i] % mod) % mod;
		
	}
	printf("%lld", ans);
}