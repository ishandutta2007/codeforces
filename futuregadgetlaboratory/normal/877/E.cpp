#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
const int N = 300033;
const int LOG = 20;
const int MOD = 1e9 + 7;
typedef complex<double> Complex;
int sum[N * 4], r[N * 4];
int fa[N], st[N], ed[N], init[N];
vector<int> sons[N];
void pushdown(int k, int l, int r) {
	if(::r[k]) {
		int le((r - l + 1 + 1) / 2);
		int ri((r - l + 1) / 2);
		::r[k * 2] ^= 1;
		::r[k * 2 + 1] ^= 1;
		sum[k * 2] = le - sum[k * 2];
		sum[k * 2 + 1] = ri - sum[k * 2 + 1];
		::r[k] = 0;
	}
}
int get(int k, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) {
		return sum[k];
	}else {
		pushdown(k, l, r);
		int mid((l + r) / 2);
		int res(0);
		if(ql <= mid) 
			res += get(k * 2, l, mid, ql, qr);
		if(qr >= mid + 1)
			res += get(k * 2 + 1, mid + 1, r, ql, qr);
		return res;
	}
}
void rev(int k, int l, int r, int ql, int qr) {
	if(ql <= l && r <= qr) {
		::r[k] ^= 1;
		sum[k] = r - l + 1 - sum[k];
	}else {
		pushdown(k, l, r);
		int mid((l + r) / 2);
		if(ql <= mid) 
			rev(k * 2, l, mid, ql, qr);
		if(qr > mid)
			rev(k * 2 + 1, mid + 1, r, ql, qr);
		sum[k] = sum[k * 2] + sum[k * 2 + 1];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i(2); i <= n; i++) {
		scanf("%d", &fa[i]);
		sons[fa[i]].push_back(i);
	}
	for(int i(1); i <= n; i++) {
		scanf("%d", &init[i]);
	}
	vector<pair<int, int > > q0;
	q0.push_back({1, 0});
	st[1] = ed[1] = 1;
	int np = 1;
	while(!q0.empty()) {
		int v(q0.back().first), p(q0.back().second++);
		if(p == sons[v].size()) {
			ed[fa[v]] = ed[v];
			q0.pop_back();
		}else {
			int y(sons[v][p]);
			st[y] = ed[y] = ++np;
			ed[fa[y]] = np;
			q0.push_back({y, 0});
		}
	}
	for(int i(1); i <= n; i++) {
		if(init[i]) {
			rev(1, 1, n, st[i], st[i]);
		}
	}
	//return 0;
	int Q;
	scanf("%d", &Q);
	for(int i(0); i < Q; i++) {
		static char tmp[99];
		int x;
		scanf("%s%d", tmp, &x);
		if(tmp[0] == 'g') {
			printf("%d\n", get(1, 1, n, st[x], ed[x]));
		}else {
			rev(1, 1, n, st[x], ed[x]);
		}
	}
}