#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

#define NDEBUG
#include <cassert>

const int MN = 1.5e5 + 100;
using ll = long long;
#define tl(X) static_cast<ll>(X)

int N, NN, a[MN], b[MN];
ll fans[MN];
ll ans;

struct BIT
{
public:
	int a[MN];
	void reset()
	{
		memset(a, 0, sizeof(a));
	}
	void upd(int x, int v)
	{
		assert(x >= 0);
		for(++x;x <= N+10;x += -x&x)
			a[x-1] += v;
	}
	int qry(int x)
	{
		assert(x >= 0);
		int r = 0;
		for(++x;x;x -= -x&x)
			r += a[x-1];
		return r;
	}
};
BIT vals, cnts;

struct segtree
{
public:
	int m[1<<19], m2[1<<19], c[1<<19], z[1<<19];
	void reset()
	{
		memset(m2, -1, sizeof(m2));
		memset(z, -1, sizeof(z));
		memset(c, 0, sizeof(c));
		memset(m, -1, sizeof(m));
	}
	void down(int n)
	{
		if(!~z[n]) return;
		for(int x : {n<<1, n<<1|1})
			if(m[x] > z[n]) z[x] = m[x] = z[n];
		z[n] = -1;
	}
	void up(int n)
	{
		if(m[n<<1] > m[n<<1|1])
			m[n] = m[n<<1], c[n] = c[n<<1], m2[n] = std::max(m2[n<<1], m[n<<1|1]);
		else if(m[n<<1] < m[n<<1|1])
			m[n] = m[n<<1|1], c[n] = c[n<<1|1], m2[n] = std::max(m2[n<<1|1], m[n<<1]);
		else
			m[n] = m[n<<1], c[n] = c[n<<1] + c[n<<1|1], m2[n] = std::max(m2[n<<1], m2[n<<1|1]);
	}
	void set(int n, int l, int r, int x, int v)
	{
		if(r-l>1)
		{
			int m = l+(r-l)/2;
			down(n);
			if(x < m) set(n<<1, l, m, x, v);
			else set(n<<1|1, m, r, x, v);
			up(n);
		}
		else
		{
			if(c[n])
				cnts.upd(m[n], -1), ans -= vals.qry(m[n]);
			m[n] = v, c[n] = 1;
			cnts.upd(m[n], 1);
			ans += vals.qry(m[n]);
		}
	}
	void upd(int n, int l, int r, int ql, int qr, int v)
	{
		if(v >= m[n]) return;
		if(v > m2[n] && ql <= l && r <= qr)
		{
			cnts.upd(m[n], -c[n]);
			ans -= tl(c[n]) * vals.qry(m[n]);
			m[n] = v;
			z[n] = v;

			cnts.upd(m[n], c[n]);
			ans += tl(c[n]) * vals.qry(m[n]);
			return;
		}
		assert(r-l>1);
		int m = l + (r-l)/2;
		down(n);
		if(ql < m) upd(n<<1, l, m, ql, qr, v);
		if(m < qr) upd(n<<1|1,m,r, ql, qr, v);
		up(n);
	}
};
segtree st;

std::set<int> use;
bool start[MN];
void solve()
{
	st.reset();
	vals.reset();
	cnts.reset();
	use.clear();
	memset(start, 0, sizeof(start));
	ans = 0LL;

	for(int i = 0, x;i < N;++i)
	{
		st.upd(1, 0, NN, 0, b[i], b[i]-1);
		//printf("TEMP: %lld\n", ans);

		std::set<int>::iterator it = use.upper_bound(b[i]);
		if(it != use.end()) 
		{
			st.set(1, 0, NN, *it, N);
			if(!start[*it])
				cnts.upd(*it-1, -1), start[*it] = 1, ans -= vals.qry(*it-1);
		}
		use.insert(b[i]);

		st.set(1, 0, NN, *use.begin(), N);
		if(!start[*use.begin()])
			cnts.upd(*use.begin()-1, -1), start[*use.begin()] = 1, ans -= vals.qry(*use.begin()-1);

		vals.upd(b[i], 1);
		ans += cnts.qry(N) - cnts.qry(b[i]-1);
		fans[i] += ans;
	}
}

int main(void)
{
	scanf("%d", &N);
	NN = 1<<18;
	for(int i = 0;i < N;++i)
		scanf("%d", a+i), b[a[i]-1] = i+1;
	solve();
	//for(int i = 0;i < N;++i) printf("MID: %lld\n", fans[i]);
	for(int i = 0;i < N;++i)
		b[i] = N+1-b[i];
	solve();
	for(int i = 0;i < N;++i)
		printf("%lld\n", fans[i]-i-1);
	return 0;
}