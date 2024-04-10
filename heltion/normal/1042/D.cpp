#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
typedef long long LL;
LL a[maxn], s[maxn], p[maxn], sum[maxn << 2];
void add(int o, int l, int r, int x, LL v){
	if(l == r) sum[o] += v;
	else{
		int m = (l + r) >> 1;
		if(x <= m) add(o << 1, l, m, x, v);
		else add(o << 1 | 1, m + 1, r, x, v);
		sum[o] = sum[o << 1] + sum[o << 1 | 1];
	}
}
LL query(int o, int l, int r, int L, int R){
	if(l >= L && r <= R) return sum[o];
	LL res = 0;
	int m = (l + r) >> 1;
	if(L <= m) res += query(o << 1, l, m, L, R);
	if(R > m) res += query(o << 1 | 1, m + 1, r, L, R);
	return res;
}
int main(){
	int n, m, q;
	LL t, ans = 0;
	scanf("%d %lld", &n, &t);
	for(int i = 1; i <= n; i += 1){
		scanf("%lld", a + i);
		p[i] = s[i] = s[i - 1] + a[i];
	}
	sort(p, p + n + 1);
	m = unique(p, p + n + 1) - p;
	
	//for(int i = 0; i <= n; i += 1) printf("%lld ", s[i]); puts("");
	//for(int i = 0; i < m; i += 1) printf("%lld ", p[i]); puts("");
	
	for(int i = 0; i <= n; i += 1){
		if(i){
			q = lower_bound(p, p + m, s[i] - t) - p;
			if(p[q] == s[i] - t) q += 1;
			if(q + 1 <= m) ans += query(1, 1, m, q + 1, m);
		}
		q = lower_bound(p, p + m, s[i]) - p;
		add(1, 1, m, q + 1, 1);
		
	}
	printf("%lld", ans);
}