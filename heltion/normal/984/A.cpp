#include<bits/stdc++.h>
#define maxn 1000
int a[maxn];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1) scanf("%d", a + i);
	std::sort(a, a + n);
	if(n & 1) printf("%d", a[(n - 1) / 2]);
	else printf("%d", a[n / 2 - 1]);
}