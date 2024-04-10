#include<bits/stdc++.h>
#define maxn 120
using namespace std;
typedef long long LL;
LL F(LL x, LL y, LL n){
	LL ans = 0;
	if((x + y) % 2 == 0){
		if(n % 2 == 0){
			ans += (x - 1) * (n / 2);
			ans += (y + 1) / 2;
		}
		else{
			if(x % 2) ans += (x - 1) / 2 * n;
			else ans += (x - 2) / 2 * n + (n + 1) / 2;
			if(x % 2) ans += (y + 1) / 2;
			else ans += y/ 2;
		}
	}
	else{
		ans = (n * n + 1) / 2;
		if(n % 2 == 0){
			ans += (x - 1) * (n / 2);
			ans += (y + 1) / 2;
		}
		else{
			if(x % 2) ans += (x - 1) / 2 * n;
			else ans += (x - 2) / 2 * n + (n - 1) / 2; 
			if(x % 2) ans += y / 2;
			else ans += (y + 1) / 2;
		}
	}
	return ans;
}
int main(){
	LL n;
	int q;
	scanf("%lld %d", &n, &q);
	for(int i = 0; i < q; i += 1){
		LL x, y;
		scanf("%lld %lld", &x, &y);
		printf("%lld\n", F(x, y, n));
	}
}