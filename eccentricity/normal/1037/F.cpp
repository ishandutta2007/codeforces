#include<bits/stdc++.h>
#define maxn 1200000
using namespace std;
typedef long long LL;
const LL P = 1000000007;
int a[maxn], mx[maxn << 2];
int mL[maxn], mR[maxn];
int n, k;
void build(int o, int l, int r){
	int m = l + r >> 1;
	if(l == r) mx[o] = a[m];
	else{
		build(o << 1, l, m);
		build(o << 1 | 1, m + 1, r);
		mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
	}
}
int queryL(int o, int l, int r, int L, int R, int v){
	int ans;
	if(L > R) return 0;
	if(mx[o] < v) return 0;
	int m = l + r >> 1;
	if(l == r) return m;
	if(R > m){
		ans = queryL(o << 1 | 1, m + 1, r, L, R, v);
		if(ans) return ans;
	}
	if(L <= m){
		ans = queryL(o << 1, l, m, L, R, v);
		return ans;
	}
	
	return 0;
}
int queryR(int o, int l, int r, int L, int R, int v){
	int ans;
	if(L > R) return n + 1;
	if(mx[o] <= v) return n + 1;
	int m = l + r >> 1;
	if(l == r) return m;
	if(L <= m){
		ans = queryR(o << 1, l, m, L, R, v);
		if(ans != n + 1) return ans;
	}
	if(R > m){
		ans = queryR(o << 1 | 1, m + 1, r, L, R, v);
		return ans;
	}
	
	return n + 1;
}


int len[maxn], len_cnt;
LL a1[maxn];
int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i += 1)
		scanf("%d", a + i);
	build(1, 1, n);
	LL ans = 0;
	len[0] = a1[0] = k;
	len_cnt += 1;
	for(int i = 1; ; i += 1){
		len[i] = len[i - 1] + k - 1;
		a1[i] = (a1[i - 1] + len[i]) % P;
		len_cnt += 1;
		if(len[i] > n) break;
	}
	for(int i = 1; i <= n; i += 1){
		LL pans = 0;
		mL[i] = queryL(1, 1, n, 1, i - 1, a[i]);
		mR[i] = queryR(1, 1, n, i + 1, n, a[i]);
		int L = i - mL[i] - 1;
		int R = mR[i] - i - 1;
		//printf("L = %d R = %d\n", mL[i], mR[i]);
		if(L > R) swap(L, R);
		
		int p = lower_bound(len, len + len_cnt, L + 1) - len;
		if(len[p] > L + 1) p -= 1;
		if(p != -1) pans = a1[p];
		
		int q = lower_bound(len, len + len_cnt, R + 1) - len;
		if(len[q] > R + 1) q -= 1;
		if(q != - 1) pans = (pans + 1LL * (q - p) * (L + 1) % P) % P;
		
		int r = lower_bound(len, len + len_cnt, L + R + 1) - len;
		if(len[r] > L + R + 1) r -= 1;
		if(r != -1) pans = (pans + 1LL * (r - q) * (R + L + 2) % P - a1[r] + (q < 0 ? 0 : a1[q]) + P) % P;
		//printf("L = %d R = %d pans = %lld\n", L, R, pans);
		ans = (ans + pans * a[i] % P) % P;
	}
	while(ans < 0) ans += P;
	printf("%lld", ans);
}