#include <iostream>
#include <cstdio>

#include <bitset>
#include <vector>

#include <cassert>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MD = 22;
const int MM = 65;
const int MN = 3e4 + 100;
const ll INF = 1e18;

using vb = bitset<MN>;
vb F[MN];

int D, M, N;
int g[MD], b[MN];

int md(int x) {
	if(x >= M) x -= M;
	assert(x < M);
	return x;
}

struct DAT {
	vb p, s;
	ll l, c;
	DAT() {
		p.reset(), s.reset();
		l = c = 0LL;
	}
	DAT operator + (const DAT& o) const {
		DAT r;
		r.c = c+o.c, r.l = l+o.l;
		if(l + 1 < N) r.p = p&o.p>>l|p>>N-l-1<<N-l-1; else r.p = p;
		if(o.l + 1< N) r.s = o.s&s<<o.l|o.s&F[o.l]; else r.s = o.s;
		if(r.l >= N) {
			vb q = s&o.p;
			if(l < N) q &= F[l];
			if(o.l < N) q >>= N-o.l-1;
			r.c += q.count();
		}
		return r;
	}
};

DAT d[100][MM];

using vi = vector<int>;
#define pb push_back

ll solve(ll v) {
	if(v <= 0) return 0LL;
	vi x(0);
	for(;v;v/=D)
		x.pb(v%D);
	DAT c;
	for(int i = x.size() - 1, r = 0;i >= 0;i--) {
		for(int j = 0;j < x[i];j++)
			c = c + d[i][md(r+g[j])];
		r = md(r + g[x[i]]);
	}
	return c.c;
}

int main() {
	F[0].reset();
	for(int i = 0;i < MN - 1;i++) F[i+1] = F[i], F[i+1][i] = 1;
	
	scanf("%d%d", &D, &M);
	for(int i = 0;i < D;i++) scanf("%d", g + i);
	scanf("%d", &N);
	for(int i = 0;i < N;i++) scanf("%d", b + i);
	b[N] = -1;
	
	for(int i = 0;i < M;i++) {
		d[0][i].l = 1;
		if(N > 1)
			for(int j = 0;j < N-1;j++)
				d[0][i].s[j] = i <= b[j], d[0][i].p[j] = i <= b[j + 1];
		else
			d[0][i].c = i <= b[0];
	}
	
	ll x = 1;
	for(int i = 1;x <= INF/D;i++, x *= D)
		for(int j = 0;j < M;j++) {
			d[i][j] = d[i-1][j];
			for(int k = 1;k < D;k++) d[i][j] = d[i][j] + d[i-1][md(j+g[k])];
		}
	
	ll A, B;
	scanf("%lld%lld", &A, &B);
	printf("%lld\n", solve(B) - solve(A+N-2));
	
	return 0;
}