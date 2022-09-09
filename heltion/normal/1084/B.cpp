#include<bits/stdc++.h>
using namespace std;
typedef long long LL; 
#define maxn 1200
int main(){
	int n;
	LL s, m = 1LL<<60, h = 0;
	scanf("%d %lld", &n, &s);
	for(int i = 0; i < n; i += 1){
		LL v;
		scanf("%lld", &v);
		m = min(m, v);
		h += v;
	}
	if(h - m * n >= s) printf("%lld", m);
	else if(h < s) printf("-1");
	else printf("%lld", m - (s - h + m * n + n - 1) / n);
}