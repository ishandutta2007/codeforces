#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
typedef long long LL; 
LL a[maxn];
int main(){
	int n;
	LL s, ans = 0;
	scanf("%d %lld", &n, &s);
	for(int i = 0; i < n; i += 1) scanf("%lld", a + i);
	sort(a, a + n);
	for(int i = 0; i < n; i += 1){
		if(i < n / 2 && a[i] > s) ans += a[i] - s;
		if(i == n / 2) ans += abs(a[i] - s);
		if(i > n / 2 && a[i] < s) ans += s - a[i];
	}
	printf("%lld", ans);
}