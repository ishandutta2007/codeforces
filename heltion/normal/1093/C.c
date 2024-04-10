#include<ctype.h>
#include<math.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long LL;
#define maxn 240000
LL a[maxn], b[maxn];
LL max(LL a, LL b){
	return a < b ? b : a;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n / 2; i += 1) scanf("%lld", b + i);
	a[1] = 0, a[n] = b[1];
	for(int i = 2; i <= n / 2; i += 1){
		a[i] = max(a[i - 1], b[i] - a[n - i + 2]);
		a[n - i + 1] = b[i] - a[i]; 
	}
	for(int i = 1; i <= n; i += 1) printf("%lld ", a[i]);
}