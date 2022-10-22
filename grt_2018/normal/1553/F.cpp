#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 300 * 1000 + 10;
int n, mx;
int A[nax];
ll ans[nax];

struct Segtree {
	ll T[(1 << 20)];
	int R;
	void init() {
		R = 1;
		while(R <= mx) R *= 2;
		for(int i = 1; i < 2 * R; ++i) T[i] = 0;
	}
	void add(int a, int x) {
		a += R;
		T[a] += x;
		while(a > 1) {
			a /= 2;
			T[a] += x;
		}
	}
	ll qr(int a, int b) {
		a += R; b += R;
		ll w = T[a] + (a != b ? T[b] : 0);
		while(a / 2 != b / 2) {
			if(a % 2 == 0) w += T[a + 1];
			if(b % 2 == 1) w += T[b - 1];
			a /= 2;
			b /= 2;
		}
		return w;
	}	
} sum, cnt;

struct Segtree2 {
	ll T[(1 << 20)];
	int R;
	void init() {
		R = 1;
		while(R <= mx) R *= 2;
		for(int i = 1; i < 2 * R; ++i) T[i] = 0;
	}
	ll qr(int a) {
		a += R;
		ll w = T[a];
		while(a > 1) {
			a /= 2;
			w += T[a];
		}
		return w;
	}
	void add(int a, int b, int x) {
		a += R; b += R;
		T[a] += x;
		if(a != b) T[b] += x;
		while(a / 2 != b / 2) {
			if(a % 2 == 0) T[a + 1] += x;
			if(b % 2 == 1) T[b - 1] += x;
			a /= 2;
			b /= 2;
		}
	}
} fut;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> A[i];
		mx = max(mx, A[i]);
	}
	sum.init();
	cnt.init();
	fut.init();
	for(int i = 1; i <= n; ++i) {
		ans[i] = ans[i - 1];
		for(int j = 0; j <= mx; j += A[i]) {
			ans[i] += sum.qr(j, min(mx, j + A[i] - 1));
			ans[i] -= cnt.qr(j, min(mx, j + A[i] - 1)) * j;
		}
		//cout << ans[i] << " " << fut.qr(A[i]) << "\n";
		ans[i] += (ll)A[i] * (i - 1) - fut.qr(A[i]);
		for(int j = 0; j <= mx; j += A[i]) {
			//cout << j << " " << j + A[i] - 1 << "\n";
			fut.add(j, min(mx, j + A[i] - 1), j);
		}
		sum.add(A[i], A[i]);
		cnt.add(A[i], 1);
		cout << ans[i] << " ";
	}
	
}