#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>
#include <array>

#include <cassert>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MN = 1e5 + 1000;
const int MM = 1e5 + 1000;

using i3 = array<int, 3>;
using i2 = array<int, 2>;
using vi3 = vector<i3>;
#define pb push_back

int a[MN], N, M;

struct DT {
public:
	vi3 v;
	int l;
	DT() {
		v.clear();
	}
	DT operator + (const DT& o) const {
		const vi3& u = o.v;
		DT f;
		f.l = l;
		int i = 0, p = 0, d = a[o.l] - a[l], t;
		for(const i3& x : v) {
			i = o.get(p + x[1] - d)[0];
			for(;u[i][0] + d < x[0] + x[1];i++)
				f.v.pb({u[i][0] + d - x[1], u[i][1] + x[1], u[i][2] + x[2]});
			f.v.pb({x[0], u[i][1] + x[1], u[i][2] + x[2]});
			p = x[0];
		}
		return f;
	}
	i3 get(int x) const {
		assert(0 <= x && x < l);
		int a = -1, b = v.size()-1;
		for(;b-a>1;) {
			int m = a + ((b-a)>>1);
			if(x < v[m][0]) b = m;
			else a = m;
		}
		return {b, v[b][1], v[b][2]};
	}
};
DT B[MN];
template<int MS = MN<<2> struct ST {
	DT v[MS];
	void build(int n, int l, int r) {
		if(r-l>1) {
			int m = l + ((r-l)>>1);
			build(n<<1, l, m), build(n<<1|1, m, r);
			v[n] = v[n<<1] + v[n<<1|1];
		} else
			v[n] = B[l];
	}
	int S, E;
	void init(int a, int b) {
		S = a, E = b;
		build(1, a, b);
	}
	i3 qry(int n, int l, int r, i3 x) {
		assert(l <= x[0] && x[0] < r);
		if(l < x[0]) {
			assert(r-l>1);
			int m = l + ((r-l)>>1);
			if(x[0] < m) {
				i3 y = qry(n<<1, l, m, x);
				if(y[0] == m) y = qry(n<<1|1, m, r, y);
				return y;
			} else
				return qry(n<<1|1, m, r, x);
		} else {
			assert(x[0] == l);
			i3 q = v[n].get(x[1]);
			if(q[2] > x[2]) {
				if(r-l>1) {
					int m = l + ((r-l)>>1);
					i3 y = qry(n<<1, l, m, x);
					if(y[0] == m) y = qry(n<<1|1, m, r, y);
					return y;
				} else
					return x;
			} else
				return {r, x[1]+q[1]-(a[r]-a[l]), x[2]-q[2]};
		}
	}
	i3 qry(i3 x) {return qry(1, S, E, x);}
};
ST<> st;

int x, k;
int qry() {
	scanf("%d%d", &x, &k);
	if(x < a[1]) return printf("%d\n", x), 0;
	if(a[N] <= x) return printf("%lld\n", tl(k)*N + x), 0;
	int w = (upper_bound(a+1, a+N+1, x)-a)-1;
	i3 f = st.qry({w, (x-a[w])%w, k + (x-a[w])/w});
	return printf("%lld\n", tl(f[2])*f[0] + a[f[0]] + f[1]), 0;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1;i <= N;i++) scanf("%d", a + i), a[i] -= i-1;
	for(int i = 1;i < N;i++) {
		int d = a[i+1] - a[i];
		B[i].l = i;
		if(d%i) {
			B[i].v.pb({d%i, (d/i+1)*i, d/i+1});
			B[i].v.pb({i, d/i*i, d/i});
		} else 
			B[i].v.pb({i, d, d/i});
	}
	st.init(1, N);
	while(M--) qry();
	
	return 0;
}