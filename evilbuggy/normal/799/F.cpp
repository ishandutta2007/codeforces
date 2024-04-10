#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

struct SegmentTree{
	long long sum[N << 2];
	int maxi[N << 2], lazy[N << 2], cnt[N << 2];

	void init(int p, int v, int l, int r){
		lazy[v] = maxi[v] = 0;
		if(l == r){
			if((l&1) == p){
				cnt[v] = 1;
				sum[v] = l - 1;
			}else{
				cnt[v] = 0;
				sum[v] = 0;
			}
			return;
		}
		int m = (l + r)/2;
		int v1 = v << 1;
		int v2 = v1 | 1;
		init(p, v1, l, m);
		init(p, v2, m + 1, r);
		cnt[v] = cnt[v1] + cnt[v2];
		sum[v] = sum[v1] + sum[v2];
	}

	void push(int v, int s, int e){
		if(lazy[v] != 0){
			maxi[v] += lazy[v];
			if(s != e){
				lazy[2*v] += lazy[v];
				lazy[2*v + 1] += lazy[v];
			}
			lazy[v] = 0;
		}
		return;
	}

	void update(int v, int s, int e, int l, int r, int x){
		if(l <= s && e <= r){
			lazy[v] += x;
			push(v, s, e);
			return;
		}
		push(v, s, e);
		if(e < l || r < s || r < l)return;
		int m = (s + e)/2;
		int v1 = v << 1;
		int v2 = v1 | 1;
		update(v1, s, m, l, r, x);
		update(v2, m + 1, e, l, r, x);
		if(maxi[v1] > maxi[v2]){
			maxi[v] = maxi[v1];
			cnt[v] = cnt[v1];
			sum[v] = sum[v1];
		}else if(maxi[v1] < maxi[v2]){
			maxi[v] = maxi[v2];
			cnt[v] = cnt[v2];
			sum[v] = sum[v2];
		}else{
			maxi[v] = maxi[v1];
			cnt[v] = cnt[v1] + cnt[v2];
			sum[v] = sum[v1] + sum[v2];
		}
	}

	long long query(int v, int s, int e, int l, int r, int n, int en){
		if(r < l)return 0;

		push(v, s, e);
		if(maxi[v] < n)return 0;
		if(l <= s && e <= r){
			return en*1LL*cnt[v] - sum[v];
		}
		int m = (s + e)/2;
		int v1 = v << 1;
		int v2 = v1 | 1;
		if(r <= m)return query(v1, s, m, l, r, n, en);
		if(m < l)return query(v2, m + 1, e, l, r, n, en);
		return query(v1, s, m, l, r, n, en) + query(v2, m + 1, e, l, r, n, en);
	}
} tree[2];

vector<int> st[N], en[N];
int n, m, l[N], r[N], f[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		st[l[i]].emplace_back(i);
		en[r[i]].emplace_back(i);
	}
	int closed = 0;
	long long answer = 0;
	multiset<int> open[2];
	tree[0].init(0, 1, 1, m);
	tree[1].init(1, 1, 1, m);
	for(int i = 1; i <= m; i++){
		for(int ind : st[i]){
			open[i&1].insert(i);
		}
		int o = i&1;
		int e = o^1;
		if(!open[e].empty()){
			int lo = *open[e].rbegin();
			answer += tree[o].query(1, 1, m, lo, i, closed, i);
		}else if(!open[o].empty()){
			int lo = *open[o].begin();
			answer += tree[o].query(1, 1, m, 1, i, closed, i);
			answer += tree[e].query(1, 1, m, 1, lo - 1, closed, i);
		}else{
			answer += tree[o].query(1, 1, m, 1, i, closed, i);
			answer += tree[e].query(1, 1, m, 1, i, closed, i);
		}
		for(int ind : en[i]){
			int lo = l[ind];
			int hi = r[ind];

			if((hi - lo)&1){
				// Even length
				tree[o].update(1, 1, m, lo, m, 1);
				tree[e].update(1, 1, m, hi + 1, m, 1);
			}else{
				// Odd length
				tree[o].update(1, 1, m, 1, m, 1);
				tree[e].update(1, 1, m, hi + 1, m, 1);
				tree[e].update(1, 1, m, 1, lo - 1, 1);
			}

			open[lo&1].erase(open[lo&1].find(lo));
			closed++;
		}
	}
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++){
		f[l[i]]++; f[r[i] + 1]--;
	}
	int cur = 0;
	for(int i = 1; i <= m; i++){
		f[i] += f[i - 1];
		if(f[i]){
			cur = 0;
		}else{
			cur++;
		}
		answer -= cur*1LL*(cur + 1)/2;
	}
	cout << answer << '\n';

	return 0;
}