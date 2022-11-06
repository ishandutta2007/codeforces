#include<bits/stdc++.h>
#define maxn 1600000
using namespace std;
typedef long long LL;
const int P = 1000000007;
int t[maxn], p[maxn], k[maxn];
LL power[maxn];
char s[maxn];
map<int, int> ma;

int mn[maxn], mx[maxn];
void update(int o, int l, int r, int x, int v){
	int m = (l + r) / 2;
	if(l == r){
		mn[o] = min(mn[o], v);
		mx[o] = max(mx[o], v);
	}
	else{
		if(x <= m) update(o * 2, l, m, x, v);
		else update(o * 2 + 1, m + 1, r, x, v);
		mn[o] = min(mn[o * 2], mn[o * 2 + 1]);
		mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
	}
}

int mnquery(int o, int l, int r, int L, int R){
	int m = (l + r) / 2;
	if(l >= L && r <= R) return mn[o];
	int res = P;
	if(L <= m) res = min(res, mnquery(o * 2, l, m, L, R));
	if(R > m) res = min(res, mnquery(o * 2 + 1, m + 1, r, L, R));
	return res;
}

int mxquery(int o, int l, int r, int L, int R){
	int m = (l + r) / 2;
	if(l >= L && r <= R) return mx[o];
	int res = 0;
	if(L <= m) res = max(res, mxquery(o * 2, l, m, L, R));
	if(R > m) res = max(res, mxquery(o * 2 + 1, m + 1, r, L, R));
	return res;
}

set<int> se; 
int main(){
	int n;
	scanf("%d", &n);
	fill(mn, mn + maxn, P);
	fill(k + 1, k + n + 1, n);
	power[0] = 1;
	for(int i = 1; i <= n; i += 1){
		power[i] = power[i - 1] * 2 % P;
		scanf("%s %d", s, p + i);
		t[i] = s[1] == 'D';
		if(t[i]) ma[p[i]] = i;
		else{
			k[ma[p[i]]] = i;
			update(1, 1, n, i, p[i]);
		}
	}
	int c = 0, dd = 0;
	int mmn = 0, mxx = P;
	for(int i = 1; i <= n; i += 1) if(t[i]){
		int x = mnquery(1, 1, n, i, k[i]);
		int d = mxquery(1, 1, n, i, k[i]);
		if(d > p[i] && p[i] > x){
			printf("0");
			return 0;
		}
		if(p[i] == x && p[i] == d) c += 1;
		if(x != P && k[i] == n && p[i] != p[n]){
			if(p[i] > d) mxx = min(mxx, p[i]);
			else mmn = max(mmn, p[i]); 
		}
		if(x == P && mmn < p[i] && mxx > p[i]) dd += 1;
	}
	printf("%lld", power[c] * (dd + 1) % P);
}