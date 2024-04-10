#include <cstdio>
#include <cassert>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const ll INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MX = 1e9;

struct frac
{
	public:
		const static frac INF;
		int n, d;
		frac(int _n=0, int _d=1): n(_n), d(_d) {if(d<0) d*=-1, n*=-1;}
		bool operator < (const frac& o) const {return (ll)n * o.d < (ll)o.n * d;}
		bool operator >= (const frac& o) const {return (ll)n * o.d >= (ll)o.n * d;}
		frac operator - () const {return frac(-n, d);}
};
const frac frac::INF = frac(1, 0);

struct Line //
{
	public:
		int m, b; // mx + b
		Line(int _m, int _b): m(_m), b(_b) {}
		mutable frac r; // up to where is this line still relevant
		frac operator * (const Line& o) const // exact point of intersection
		{
			if(m == o.m)
				return b < o.b ? frac::INF : -frac::INF;
			return frac(o.b - b, m - o.m);
		}
		ll operator [] (const frac& x) const {return (ll)m * x.n + (ll)b * x.d;}
};

/*
 * (L - L_0) * y + (Hf - H_min) * x
 * L - L_0, Hf - H_min are variables
 * => Lv (inc), Hv (dec)
 * => y * Lv / Hv + x
 * Lv / Hv inc, insert lines in increasing y (right to left)
 */
struct CHT: public std::vector<Line> // min cht, query increasing x-values, slopes inserted in <y * i + (H-x) * (W-j)>, +y, +x orderA; i/(W-j) = x, increasing slope; behaves like stack
{
	private:
		typedef iterator IT;
		IT cur;
		bool upd(IT a, IT b)
		{
			if(b == end()) return a->r = frac::INF, 0;
			if((a->r = *a**b) >= b->r) return 1;
			return 0;
		}
	public:
		void ins(const Line& o)
		{
			assert(empty() || back().m > o.m);
			push_back(o);
			IT n=std::prev(end()), c=n++, p;
			for(;upd(c, n);) erase(n);
			if((p=c) != begin() && upd(--p, c)) assert(0); // slopes should be inserted in decreasing value
			for(c=p;(p=c) != begin() && upd(--p, c);) erase(c);
		}
		void prepare() {cur = begin();}
		ll operator [](const frac& x) // queries should be processed in increasing value
		{
			if(empty()) return INFL;
			for(;cur->r < x;++cur) assert(cur != end());
			return (*cur)[x];
		}
};

struct ST
{
	private:
		size_t sz;
		std::vector<CHT> st;
	public:
		ST(size_t _sz): sz(_sz) {st.assign(sz*2, CHT());}
		void upd(size_t n, const Line& v)
		{
			assert(n < sz);
			for(n+=sz;n;n>>=1)
				st[n].ins(v);
		}
		void prepare() {for(auto& x:st) x.prepare();}
		ll qry(size_t l, size_t r, const frac& x)
		{
			ll opt = INFL;
			for(l += sz, r += sz;l < r;l>>=1, r>>=1)
			{
				if(l&1) ckmin(opt, st[l++][x]);
				if(r&1) ckmin(opt, st[--r][x]);
			}
			return opt;
		}
};

ll opposite(const std::vector<int>& x, const std::vector<int>& y, const std::vector<int>& ordx, const std::vector<int>& ordy)
{
	ll opt = INFL;

	std::vector<int> mq;
	for(int i=0;i<ordx.size();++i)
	{
		//  if not while because there should never be 2 items with same x-values
		if(!mq.empty() && y[ordx[i]] > y[mq.back()] && x[ordx[i]] == x[mq.back()]) // because y values not necessarily sorted increasing to decreasing
			mq.pop_back();
		if(mq.empty() || y[ordx[i]] > y[mq.back()])
			mq.push_back(ordx[i]);
	}

	ST st((int)mq.size()-1);
	for(int i=(int)mq.size()-2;i>=0;--i)
		st.upd(i, Line(y[mq[i]] - y[ordy[0]], x[ordx.back()] - x[mq[i+1]]));
	st.prepare();

	auto fstTrue = [&](const std::vector<int>& x, const auto& f)
	{
		int l=-1, r=x.size();
		for(;r-l>1;)
		{
			int m=l+(r-l)/2;
			if(f(x[m])) r = m;
			else l = m;
		}
		return r;
	};
	auto lstTrue = [&](const std::vector<int>& x, const auto& f)
	{
		int l=-1, r=x.size();
		for(;r-l>1;)
		{
			int m=l+(r-l)/2;
			if(f(x[m])) l = m;
			else r = m;
		}
		return l;
	};

	std::vector<int> minr(ordx.size());
	minr.back() = y[ordx.back()];
	for(int i=(int)ordx.size()-2;i>=0;--i)
		minr[i] = std::min(minr[i+1], y[ordx[i]]);
	for(int i=0;i+1<ordx.size();++i)
	{
		int Lv = x[ordx[i]] - x[ordx[0]]; // increasing
		int Hv = y[ordy.back()] - minr[i+1]; // decreasing
		if(Hv == 0) continue;

		int lb = fstTrue(mq, [&](int k){return y[k] >= minr[i+1];});
		int rb = lstTrue(mq, [&](int k){return x[k] <= x[ordx[i]];});
		//printf("%d %d %d v: %d %d ans: %lld\n", i, lb, rb, Lv, Hv, lb < rb ? st.qry(lb, rb, {Lv, Hv}) : -1);
		if(lb < rb) ckmin(opt, st.qry(lb, rb, {Lv, Hv}));
	}
	return opt;
}

struct RMQ
{
	private:
		int size;
		std::vector<ll> st;
	public:
		RMQ(int _size): size(_size), st(_size*2, INFL) {};
		void set(int id, ll v)
		{
			for(id += size;id;id>>=1)
				ckmin(st[id], v);
		}
		ll rmq(int l, int r)
		{
			//printf("%d %d %d\n", l, r, size);
			assert(0 <= l && l <= r && r <= size);
			ll ans=INFL;
			for(l += size, r += size;l < r;l>>=1,r>>=1)
			{
				if(l&1) ckmin(ans, st[l++]);
				if(r&1) ckmin(ans, st[--r]);
			}
			return ans;
		}
};

ll cross(const std::vector<int>& x, const std::vector<int>& y, const std::vector<int>& ordx, const std::vector<int>& ordy)
{
	ll opt = INFL;
	int N=x.size();

	std::vector<int> x_rel = x;
	std::sort(x_rel.begin(), x_rel.end());
	x_rel.resize(std::distance(x_rel.begin(), std::unique(x_rel.begin(), x_rel.end())));

	int W = x[ordx.back()] - x[ordx[0]];
	int H = y[ordy.back()] - y[ordy[0]];

	RMQ both((int)x_rel.size()-1), top((int)x_rel.size()-1), bot((int)x_rel.size()-1);
	/*
	 * IF the horizontal box is required to cover all points with x <= (index)
	 * This stores the contribution to the answer for each x
	 * 
	 * Notably:
	 *   when both upper and bottom constraints are relevant: W ( u-d ) - LH
	 *   only top constraint is relevant: Wu - LH
	 *   only bottom constriant is relevant: -Wd - LH
	 */
	std::vector<int> maxl(x_rel.size()), minl(x_rel.size()), maxr(x_rel.size()), minr(x_rel.size());
	for(int i=0, j=0;i<x_rel.size();++i)
	{
		if(i==0) minl[i] = INF, maxl[i] = -INF;
		else minl[i]=minl[i-1], maxl[i]=maxl[i-1];
		for(;j<N && x[ordx[j]] == x_rel[i];++j)
		{
			ckmin(minl[i], y[ordx[j]]);
			ckmax(maxl[i], y[ordx[j]]);
		}
		if(i+1 < x_rel.size())
		{
			both.set(i, (ll)W * (maxl[i] - minl[i]) - (ll)x_rel[i+1] * H);
			top.set(i, (ll)W * maxl[i] - (ll)x_rel[i+1] * H);
			bot.set(i, (ll)W * -minl[i] - (ll)x_rel[i+1] * H);
		}
	}
	maxr.back() = minr.back() = y[ordx.back()]; // must be some same value so line sweep doesnt break
	for(int i=(int)x_rel.size()-2, j=N-1;i>=0;--i) // minr, maxr exclusive
	{
		minr[i]=minr[i+1], maxr[i]=maxr[i+1];
		for(;j>=0 && x[ordx[j]] == x_rel[i+1];--j)
		{
			ckmin(minr[i], y[ordx[j]]);
			ckmax(maxr[i], y[ordx[j]]);
		}
	}

	//for(int i=0;i<x_rel.size();++i) printf("%d %d %d %d\n", minl[i], maxl[i], minr[i], maxr[i]);

	auto fstTrue=[&](const std::vector<int>& a, int k, const auto& f)
	{
		int l=-1, r=a.size();
		for(;r-l>1;)
		{
			int m=l+(r-l)/2;
			if(f(a[m], k)) r=m;
			else l=m;
		}
		return r;
	};
	for(int i=0;i+1<x_rel.size();++i) // line sweep
	{
		int top_bound = std::min(fstTrue(maxl, maxr[i], std::greater<int>()), i); // leftmost point st maxl > maxr[i]
		int bot_bound = std::min(fstTrue(minl, minr[i], std::less<int>()), i); // leftmost point st minl < minr[i]
		if(std::max(top_bound, bot_bound) < i) ckmin(opt, (ll) H * x_rel[i] + both.rmq(std::max(top_bound, bot_bound), i)); // ONLY use LHS constraints
		if(top_bound < bot_bound) ckmin(opt, (ll) H * x_rel[i] + top.rmq(top_bound, bot_bound) - (ll) W * minr[i]); // uses both LHS and RHS constraints
		if(bot_bound < top_bound) ckmin(opt, (ll) H * x_rel[i] + bot.rmq(bot_bound, top_bound) + (ll) W * maxr[i]);
		ckmin(opt, (ll) (maxr[i] - minr[i]) * W + (ll) (x_rel[i] - x_rel[std::min(top_bound, bot_bound)]) * H); // ONLY use RHS constraints
	}
	ckmin(opt, both.rmq(0, (int)x_rel.size()-1) + (ll) x_rel.back() * H); // when right bound is rightmost coord

	return opt;
}

ll vertical_cut(const std::vector<int>& x, const std::vector<int>& y, const std::vector<int>& ordx, const std::vector<int>& ordy)
{
	ll opt = INFL;
	int N=x.size();

	std::vector<int> maxup(N), minup(N), maxdw(N), mindw(N);
	maxup.back() = minup.back() = x[ordy.back()];
	for(int i=N-2;i>=0;--i)
	{
		maxup[i] = std::max(maxup[i+1], x[ordy[i]]);
		minup[i] = std::min(minup[i+1], x[ordy[i]]);
	}
	maxdw[0] = mindw[0] = x[ordy[0]];
	for(int i=1;i<N;++i)
	{
		maxdw[i] = std::max(maxdw[i-1], x[ordy[i]]);
		mindw[i] = std::min(mindw[i-1], x[ordy[i]]);
	}

	for(int i=0;i+1<N;++i)
		ckmin(opt, (ll) (y[ordy.back()] - y[ordy[i+1]]) * (maxup[i+1] - minup[i+1]) + (ll) (y[ordy[i]] - y[ordy[0]]) * (maxdw[i] - mindw[i]));
	return opt;
}

void solve()
{
	int N;
	scanf("%d", &N);
	std::vector<int> x(N), y(N), ordx(N), ordy(N);
	for(int i=0;i<N;++i)
		scanf("%d%d", &x[i], &y[i]);
	if(N <= 2)
		return (void) printf("0\n");
	std::iota(ordx.begin(), ordx.end(), 0);
	std::iota(ordy.begin(), ordy.end(), 0);
	std::sort(ordx.begin(), ordx.end(), [&](int a, int b){return x[a]<x[b] || !(x[b]<x[a]) && y[a]<y[b];});
	std::sort(ordy.begin(), ordy.end(), [&](int a, int b){return y[a]<y[b] || !(y[b]<y[a]) && x[a]<x[b];});

	ll ans = INFL;
	ckmin(ans, vertical_cut(x, y, ordx, ordy));
	ckmin(ans, vertical_cut(y, x, ordy, ordx));
	ckmin(ans, cross(x, y, ordx, ordy));
	ckmin(ans, opposite(x, y, ordx, ordy));
	for(int& k:x) k=MX-k;
	std::reverse(ordx.begin(), ordx.end());
	ckmin(ans, opposite(x, y, ordx, ordy));
	printf("%lld\n", ans);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) solve();
	return 0;
}