#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1e6;
const int SIZE2 = 1e6 + 5;
typedef long long ll;

ll arr[SIZE];
int seg[SIZE];
int lazy[SIZE];
int l[SIZE];
int r[SIZE];
ll soma[SIZE];
set<pair<ll, int>> setSomas;
int n;
int qntSomas = 1;
	
void build(int idx = 0, int l = 0, int r = n - 1) {
	lazy[idx] = 0;
	if(l == r) {
		seg[idx] = arr[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*idx+1, l, mid); build(2*idx+2, mid + 1, r);
	seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

int query(int L, int R, int idx = 0, int l = 0, int r = n - 1) {
	if(lazy[idx]) {
		seg[idx] = lazy[idx];
		//printf("de %d ate %d agora eh %d 1\n", l, r, seg[idx]);
		if(l != r) {
			lazy[2*idx+1] = lazy[idx];
			//printf("lazy antes eh %d\n", lazy[2*idx+2]);
			lazy[2*idx+2] = lazy[idx];
			//printf("lazy depois agora eh %d\n", lazy[2*idx+2]);
		}
		lazy[idx] = 0;
	}
	if(l > R || r < L) return 0;
	//printf("querying de %d ate %d tou de %d ate %d com lazy = %d\n", L, R, l, r, lazy[idx]);

	if(L <= l && R >= r) return seg[idx];
	int mid = (l+r)/2;
	return query(L, R, 2*idx+1, l, mid) + query(L, R, 2*idx+2, mid +1, r);
}

void update(int L,int R,  int v, int idx = 0, int l = 0, int r = n - 1) {
	if(lazy[idx]) {
		seg[idx] = lazy[idx];
		//printf("de %d ate %d agora eh %d 1\n", l, r, seg[idx]);
		if(l != r) {
			lazy[2*idx+1] = lazy[idx];
			//printf("lazy antes eh %d\n", lazy[2*idx+2]);
			lazy[2*idx+2] = lazy[idx];
			//printf("lazy depois agora eh %d\n", lazy[2*idx+2]);
		}
		lazy[idx] = 0;
	}
	if(l > R || r < L) return;	
	if(L <= l && R >= r) {
		seg[idx] = v;
		//printf("de %d ate %d agora eh %d\n", l, r, seg[idx]);
		//cout << seg[idx] << " oi " << '\n';
		if(l != r) {
			lazy[2*idx+1] = v;
			lazy[2*idx+2] = v;
		}
		return;
	}
	int mid = (l+r)/2;
	update(L, R, v, 2*idx + 1, l, mid); update(L, R, v, 2*idx+2, mid + 1, r);
	seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

void crieSoma(int l2, int r2) {
	if(l2 > r2) return;
	ll mySum = l2 ? (arr[r2] - arr[l2-1]) : arr[r2];
	soma[qntSomas] = mySum;
	l[qntSomas] = l2;
	r[qntSomas] = r2;
	setSomas.insert(make_pair(-mySum, qntSomas));
	update(l2, r2, qntSomas);
	qntSomas++;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		if(i) arr[i] += arr[i-1];
	}
	soma[0] = arr[n - 1];
	l[0] = 0;
	r[0] = n - 1;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		x--;
		int pos = query(x, x);
		setSomas.erase(make_pair(-soma[pos], pos));
		crieSoma(l[pos], x - 1); crieSoma(x + 1, r[pos]);
		if(setSomas.empty()) cout << 0 << '\n';
		else cout << -setSomas.begin()->first << '\n';
	}
	return 0;
}