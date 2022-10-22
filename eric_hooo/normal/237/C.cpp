#include <bits/stdc++.h>
using namespace std;

int a, b, k;
int vis[1000010];
int sum[1000010];

void get_prime2(){
	for (int i = 0; i <= 1000000; i++){
		vis[i] = 1;
	}
	vis[1] = 0;
	for (int i = 2; i <= 1000000; i++){
		if (!vis[i]) continue;
		for (long long j = 1ll * i * i; j <= 1000000; j += i){
			vis[j] = 0;
		}
	}
	for (int i = 1; i <= 1000000; i++){
		sum[i] = sum[i - 1] + vis[i];
	}
}

bool check(int mid){
	for (int i = a; i <= b - mid + 1; i++){
		if (sum[i + mid - 1] - sum[i - 1] < k) return 0;
	}
	return 1;
}

void func2(){
	get_prime2();
	int l = 1, r = b - a + 1;
	while (l < r){
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	if (check(l)) printf("%d\n", l);
	else printf("-1\n");
}

bool prime(int x){
	if (x < 2) return 0;
	for (int i = 2; i * i <= x; i++){
		if (x % i == 0) return 0;
	}
	return 1;
}

void get_prime1(){
	for (int i = a; i <= b; i++){
		int x = prime(i);
		sum[i] = sum[i - 1] + x;
	}
}

void func1(){
	get_prime1();
	for (int i = k; i <= b - a + 1; i++){
		int flag = 1;
		for (int j = a; j <= b - i + 1; j++){
			if (sum[j + i - 1] - sum[j - 1] < k){
				flag = 0;
				break;
			}
		}
		if (flag){
			printf("%d\n", i);
			return ;
		}
	}
	printf("-1\n");
}

int main(){
	scanf("%d%d%d", &a, &b, &k);
	if (b - a + 1 <= 10000) func1();
	else func2();
	return 0;
}