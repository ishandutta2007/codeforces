#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 120000 << 2;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
struct SGT{
	int sum[maxn], lazy[maxn];
	SGT(){
		fill(lazy, lazy + maxn, -1);
	}
	void push_down(int x, int l, int r){
		if(~lazy[x]){
			int m = (l + r) >> 1;
			lazy[ls(x)] = lazy[x];
			sum[ls(x)] = lazy[x] * (m - l + 1);
			lazy[rs(x)] = lazy[x];
			sum[rs(x)] = lazy[x] * (r - m);
			lazy[x] = -1;
		}
	}
	void update(int x, int l, int r, int L, int R, int v){
		//cout << "update" << x << " " << l << " " << r << " " << L << " " << R << endl;
		if(l >= L and r <= R) lazy[x] = v, sum[x] = v * (r - l + 1);
		else{
			int m = (l + r) >> 1;
			push_down(x, l, r);
			if(L <= m) update(ls(x), l, m, L, R, v);
			if(R > m) update(rs(x), m + 1, r, L, R, v);
			sum[x] = sum[ls(x)] + sum[rs(x)];
		}
	}
	int query(int x, int l, int r, int L, int R){
		//cout << "query" << x << " " << l << " " << r << " " << L << " " << R << endl;
		if(l >= L and r <= R) return sum[x];
		int res = 0, m = (l + r) >> 1;
		push_down(x, l, r);
		if(L <= m) res += query(ls(x), l, m, L, R);
		if(R > m) res += query(rs(x), m + 1, r, L, R);
		return res;
	}
}sgt[26];
char s[maxn];
int c[26];
int main(){
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q >> (s + 1);
	for(int i = 1; i <= n; i += 1) sgt[s[i] - 'a'].update(1, 1, n, i, i, 1);
	for(int i = 1; i <= q; i += 1){
		int L, R, K;
		cin >> L >> R >> K;
		for(int i = 0; i < 26; i += 1){
			c[i] = sgt[i].query(1, 1, n, L, R);
			//cout << char(i + 'a') << c[i] << endl;
			sgt[i].update(1, 1, n, L, R, 0); 
		}
		if(K){
			for(int i = 0; i < 26; i += 1) if(c[i]){
				sgt[i].update(1, 1, n, L, L + c[i] - 1, 1);
				L += c[i];
			}
		}
		else{
			for(int i = 26; ~i; i -= 1) if(c[i]){
				sgt[i].update(1, 1, n, L, L + c[i] - 1, 1);
				L += c[i];
			}
		}
	}
	for(int i = 0; i < 26; i += 1)
		for(int j = 1; j <= n; j += 1)
			if(sgt[i].query(1, 1, n, j, j))
				s[j] = i + 'a';
	cout << s + 1;
}