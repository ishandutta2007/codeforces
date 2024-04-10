#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int ans = 2 * maxn, ansk;
	for(int k = 1; k <= n ; k += 1){
		if(ans > k + n / k + !!(n % k)){
			ans = k + n / k + !!(n % k);
			ansk = k;
		}
	}
	int k = ansk;
	for(int i = n % k; i >= 1; i -= 1){
		printf("%d ", i);
	}
	for(int i = 1; i <= n / k; i += 1){
		for(int j = k; j >= 1; j -= 1){
			printf("%d ", n % k + (i - 1) * k + j);
		}
	}
}