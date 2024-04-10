#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

// MAGIC IO
inline char get(void) {
	static char buf[100000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
inline void read(int &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}
void readchar(char& c) {
	while (isspace(c = get()));
}
// END MAGIC IO

const int N = 1e6+1;
int D[N];

void precompute() {
	bitset<N> np;
	int limN = sqrt(N);
	for (int i=2; i<=limN; i++) {
		if (!np[i]) {
			for (int j=i*i; j<N; j+=i) {
				np[j] = true;
			}
		}
	}
	vector<int> primes;
	for (int i=2; i<N; i++) {
		if (!np[i]) primes.push_back(i);
	}

	for (int i=1; i<N; i++) {
		int n = i;
		int lim = sqrt(n);
		D[i] = 1;
		for (int j : primes) {
			if (j > lim) break;
			int cnt = 0;
			while (n%j == 0) {
				n/=j;
				cnt++;
			}
			D[i] *= cnt+1;
		}
		if (n>1) {
			D[i] *= 2;
		}
	}
}

const int M = 1<<19;
bool lazy[2*M];
int segt[2*M], ones[2*M];
ll sum[2*M], ds[2*M];

void push(int i) {
	if (lazy[i]) {
		if (segt[i] == 1) ones[2*i] = ones[2*i+1] = ones[i]/2;
		if (segt[2*i] != 1) segt[2*i] = segt[i];
		if (segt[2*i+1] != 1) segt[2*i+1] = segt[i];
		lazy[2*i] = lazy[2*i+1] = true;
		lazy[i] = false;
	}
}

void pull(int i) {
	ones[i] = ones[2*i] + ones[2*i+1];
	if (segt[2*i] == 1) {
		segt[i] = segt[2*i+1];
	} else if (segt[2*i+1] == 1) {
		segt[i] = segt[2*i];
	} else if (segt[2*i] == segt[2*i+1]) {
		segt[i] = segt[2*i];
	} else {
		segt[i] = 0;
	}
}

void pushsum(int i, int len) {
	push(i);
	if (ds[i]) {
		sum[2*i] += ds[i] * (len/2 - ones[2*i]);
		sum[2*i+1] += ds[i] * (len/2 - ones[2*i+1]);
		ds[2*i] += ds[i];
		ds[2*i+1] += ds[i];
		ds[i] = 0;
	}
}

void pullsum(int i) {
	sum[i] = sum[2*i] + sum[2*i+1];
}

void build() {
	for (int i=M-1; i>0; i--) {
		pull(i);
		pullsum(i);
	}
}

void updatesum(int l, int r, int v, int i=1, int s=0, int e=M-1) {
	if (r<s || e<l) return;
	if (l<=s && e<=r) {
		sum[i] += (ll)v*(e-s+1-ones[i]);
		ds[i] += v;
		return;
	}
	pushsum(i,e-s+1);
	int m = (s+e)/2;
	updatesum(l,r,v,2*i,s,m);
	updatesum(l,r,v,2*i+1,m+1,e);
	pullsum(i);
}

void update(int l, int r, int i=1, int s=0, int e=M-1) {
	if (r<s || e<l) return;
	if (l<=s && e<=r && segt[i]) {
		if (D[segt[i]] == 1) ones[i] = e-s+1;
		updatesum(s, e, D[segt[i]]-segt[i]);
		segt[i] = D[segt[i]];
		lazy[i] = true;
		return;
	}
	push(i);
	int m = (s+e)/2;
	update(l,r,2*i,s,m);
	update(l,r,2*i+1,m+1,e);
	pull(i);
}

ll query(int l, int r, int i=1, int s=0, int e=M-1) {
	if (r<s || e<l) return 0;
	if (l<=s && e<=r) return sum[i];
	pushsum(i,e-s+1);
	int m = (s+e)/2;
	return query(l,r,2*i,s,m) + query(l,r,2*i+1,m+1,e);
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	precompute();

	int n, m;
	read(n); read(m);

	for (int i=0; i<n; i++) {
		int a;
		read(a);
		segt[M+i+1] = a;
		sum[M+i+1] = a;
		ones[M+i+1] = (a==1);
	}
	build();

	for (int i=0; i<m; i++) {
		int t, l, r;
		read(t); read(l); read(r);
		if (t==1) {
			update(l,r);
		} else {
			cout << query(l,r) << nl;
		}
	}

	return 0;
}