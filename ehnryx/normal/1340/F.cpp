//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;

// MAGIC IO
inline char get(void) {
	static char buf[100000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
template <typename T> inline void read(T &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}
void readchar(char& c) {
	while (isspace(c = get()));
}
// END MAGIC IO

typedef long long ll;

const char nl = '\n';

const ll P = 1e6 + 3;
const ll MOD = 1e9 + 9;

ll power(ll n, ll e, ll m) {
	ll r = 1;
	for(;e;e/=2) {
		if(e&1) r = r*n % m;
		n = n*n % m;
	}
	return r;
}

struct Node {
	bool ok;
	int plen, phash, slen, shash;
	Node(int v=0): ok(true), plen(0), phash(0), slen(0), shash(0) {
		if(v > 0) {
			slen = 1;
			shash = v;
		} else if(v < 0) {
			plen = 1;
			phash = -v;
		}
	}
};

ostream& operator << (ostream& os, const Node& v) {
	return os << v.ok << "; " << v.plen << " " << v.phash << ", " << v.slen << " " << v.shash;
}

const int N = 1<<17;
Node st[2*N];
ll pto[N], invp[N];

int get_prefix(int i, int len) {
	if(len == 0) return 0;
	if(len == st[i].plen) return st[i].phash;
	int l = 2*i;
	int r = 2*i+1;
	if(len <= st[l].plen) {
		return get_prefix(l, len);
	} else {
		int tail = get_prefix(r, len - st[l].plen + st[l].slen);
		tail = (tail - st[l].shash) * invp[st[l].slen] % MOD;
		int res = (st[l].phash + tail * pto[st[l].plen]) % MOD;
		return res < 0 ? res + MOD : res;
	}
}

int get_suffix(int i, int len) {
	if(len == 0) return 0;
	if(len == st[i].slen) return st[i].shash;
	int l = 2*i;
	int r = 2*i+1;
	if(len <= st[r].slen) {
		return get_suffix(r, len);
	} else {
		int tail = get_suffix(l, len - st[r].slen + st[r].plen);
		tail = (tail - st[r].phash) * invp[st[r].plen] % MOD;
		int res = (st[r].shash + tail * pto[st[r].slen]) % MOD;
		return res < 0 ? res + MOD : res;
	}
}

Node merge(const Node& left, const Node& right, int l, int r) {
	Node res;
	if(left.slen <= right.plen) {
		int prefix = get_prefix(r, left.slen);
		if(prefix != left.shash) {
			res.ok = false;
		} else {
			res.ok = true;
			int tail = (right.phash + MOD - prefix) * invp[left.slen] % MOD;
			res.phash = (left.phash + tail * pto[left.plen]) % MOD;
			res.plen = left.plen + right.plen - left.slen;
			res.shash = right.shash;
			res.slen = right.slen;
		}
	} else { // right.plen <= left.slen
		int suffix = get_suffix(l, right.plen);
		if(suffix != right.phash) {
			res.ok = false;
		} else {
			res.ok = true;
			int tail = (left.shash + MOD - suffix) * invp[right.plen] % MOD;
			res.shash = (right.shash + tail * pto[right.slen]) % MOD;
			res.slen = right.slen + left.slen - right.plen;
			res.phash = left.phash;
			res.plen = left.plen;
		}
	}

	// this is necessary for getting prefix/suffix in query
	if(!res.ok) {
		res.plen = left.plen;
		res.phash = left.phash;
		res.slen = right.slen;
		res.shash = right.shash;
	}
	res.ok &= left.ok & right.ok;
	return res;
}

void pull(int i) {
	st[i] = merge(st[2*i], st[2*i+1], 2*i, 2*i+1);
}

void insert(int i, int v) {
	i += N;
	st[i] = Node(v);
	for(i/=2; i>0; i/=2) {
		pull(i);
	}
}

Node query(int l, int r, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return Node();
	if(l<=s && e<=r) {
		return st[i];
	}
	int m = (s+e) / 2;
	Node left = query(l, r, 2*i, s, m);
	Node right = query(l, r, 2*i+1, m+1, e);
	return merge(left, right, 2*i, 2*i+1);
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	//ios::sync_with_stdio(0); cin.tie(0);

	pto[0] = invp[0] = 1;
	for(int i=1; i<N; i++) {
		pto[i] = pto[i-1] * P % MOD;
		invp[i] = power(pto[i], MOD-2, MOD);
	}

	int n, k;
	//cin >> n >> k;
	read(n); read(k);
	for(int i=1; i<=n; i++) {
		int v;
		//cin >> v;
		read(v);
		insert(i, v);
	}

	int m;
	//cin >> m;
	read(m);
	for(int i=0; i<m; i++) {
		int t;
		//cin >> t;
		read(t);
		if(t == 1) {
			int x, v;
			//cin >> x >> v;
			read(x); read(v);
			insert(x, v);
		} else {
			int l, r;
			//cin >> l >> r;
			read(l); read(r);
			Node res = query(l, r);
			if(res.ok && res.plen == 0 && res.slen == 0) {
				//cout << "Yes" << nl;
				puts("Yes");
			} else {
				//cout << "No" << nl;
				puts("No");
			}
		}
	}

	return 0;
}