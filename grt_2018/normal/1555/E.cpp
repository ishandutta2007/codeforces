#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 300 * 1000 + 10, INF = 1e9 + 10;
int n, m;
vector<tuple<int,int,int>> seg;
pi T[(1 << 21)];

void add(int a, int b, int x, int l, int r, int v) {
	if(a <= l && r <= b) {
		T[v].ND += x;
		return;
	}
	int mid = (l + r) / 2;
	if(a <= mid) add(a,b,x,l,mid,v*2);
	if(mid < b) add(a,b,x,mid+1,r,v*2+1);
	T[v].ST = min(T[2*v].ST + T[2*v].ND, T[2*v+1].ST + T[2*v+1].ND);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	seg.resize(n);
	for(int l,r,w,i = 0; i < n; ++i) {
		cin >> l >> r >> w;
		r--;
		seg[i] = {w, l, r};
	}
	sort(seg.begin(), seg.end());
	int ptr = 0, mx = -1;
	int ans = INF;
	for(int i = 0; i < n; ++i) {
		while(ptr < n && T[1].ST + T[1].ND == 0) {
			auto &[w,l,r] = seg[ptr];
			add(l,r,1,1,m-1,1);
			mx = w;
			ptr++;
		}
		auto &[w, l, r] = seg[i];
		if(T[1].ST + T[1].ND > 0) {
			ans = min(ans, mx - w);
		}
		add(l, r, -1, 1, m - 1, 1);
	}
	cout << ans;
}