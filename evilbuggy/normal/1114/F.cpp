#include <bits/stdc++.h>
using namespace std;

const int M = 301;
const int N = 400005;
const int mod = 1000000007;

vector<int> primes;
long long mask[N << 2], lama[N << 2];
int n, q, psz, a[N], tree[N << 2], lazy[N << 2], invmul[M];

inline int power(int a, int b){
	int ret = 1;
	while(b){
		if(b&1)ret = ret*1LL*a%mod;
		a = a*1LL*a%mod;
		b >>= 1;
	}
	return ret;
}

void init(){
	for(int i = 2; i < M; i++){
		bool flg = true;
		for(int j = 2; j*j <= i; j++){
			if(i%j == 0){
				flg = false;
				break;
			}
		}
		if(flg){
			primes.emplace_back(i);
		}
	}
	psz = (int)primes.size();
	for(int i = 0; i < psz; i++){
		invmul[i] = power(primes[i], mod - 2)*1LL*(primes[i] - 1)%mod;
	}
}

void build(int v, int l, int r){
	lazy[v] = 1;
	lama[v] = 0;
	if(l == r){
		tree[v] = a[l];
		mask[v] = 0;
		for(int j = 0; j < psz; j++){
			if(a[l]%primes[j] == 0){
				mask[v] |= (1LL << j);
			}
		}
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	build(v1, l, m);
	build(v2, m + 1, r);
	mask[v] = mask[v1]|mask[v2];
	tree[v] = tree[v1]*1LL*tree[v2]%mod;
}

inline void push(int v, int s, int e){
	if(lama[v] > 0){
		tree[v] = tree[v]*1LL*power(lazy[v], e - s + 1)%mod;
		mask[v] = mask[v]|lama[v];
		if(s != e){
			lama[2*v] = lama[2*v]|lama[v];
			lama[2*v + 1] = lama[2*v + 1]|lama[v];

			lazy[2*v] = lazy[2*v]*1LL*lazy[v]%mod;
			lazy[2*v + 1] = lazy[2*v + 1]*1LL*lazy[v]%mod;
		}
		lazy[v] = 1;
		lama[v] = 0;
	}
}

void update(int v, int s, int e, int l, int r, int x, long long ma){
	if(l <= s && e <= r){
		lazy[v] = lazy[v]*1LL*x%mod;
		lama[v] |= ma;
		push(v, s, e);
		return;
	}
	push(v, s, e);
	if(r < s || e < l)return;
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	update(v1, s, m, l, r, x, ma);
	update(v2, m + 1, e, l, r, x, ma);
	mask[v] = mask[v1]|mask[v2];
	tree[v] = tree[v1]*1LL*tree[v2]%mod;
}

pair<int, long long> query(int v, int s, int e, int l, int r){
	push(v, s, e);
	if(l <= s && e <= r)return {tree[v], mask[v]};
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(r <= m)return query(v1, s, m, l, r);
	if(m < l)return query(v2, m + 1, e, l, r);
	pair<int, long long> p1 = query(v1, s, m, l, r);
	pair<int, long long> p2 = query(v2, m + 1, e, l, r);
	return {p1.first*1LL*p2.first%mod, p1.second|p2.second};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	build(1, 1, n);

	int l, r, x;
	string command;
	while(q--){
		cin >> command >> l >> r;
		if(command[0] == 'M'){
			cin >> x;
			long long ma = 0;
			for(int j = 0; j < psz; j++){
				if(x%primes[j] == 0)ma |= (1LL << j);
			}
			update(1, 1, n, l, r, x, ma);
		}else{
			pair<int, long long> pp = query(1, 1, n, l, r);
			int ans = pp.first;
			for(int j = 0; j < psz; j++){
				if((pp.second >> j) & 1){
					ans = ans*1LL*invmul[j]%mod;
				}
			}
			cout << ans << '\n';
		}
	}

	return 0;
}