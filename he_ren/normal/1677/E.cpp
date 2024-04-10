#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXQ = 1e6 + 5;

namespace FastIO
{
	const int SIZ1 = 1<<23;
	const int SIZ2 = 1<<22;
	char buf1[SIZ1], buf2[SIZ2], *s1 = buf1, *t1 = buf1, *s2 = buf2, *t2 = buf2;
	inline char gc(void)
	{
		if(s1 == t1)
		{
			t1 = buf1 + fread(s1=buf1,1,SIZ1,stdin);
			if(s1 == t1) return EOF;
		}
		return *s1++;
	}
	inline void flush(void)
	{
		fwrite(s2,1,t2-s2,stdout); t2 = s2;
	}
	inline void pc(char c)
	{
		if(t2 - s2 == SIZ2) flush();
		*t2++ = c;
	}
	inline int read(void)
	{
		int res=0;
		char c=gc();
		while(c<'0'||c>'9') c=gc();
		while(c>='0'&&c<='9') res=res*10+c-'0', c=gc();
		return res;
	}
	inline void write(ll x)
	{
		if(x>=10) write(x/10);
		pc(x%10 + '0');
	}
} using FastIO::read; using FastIO::write;

struct Data
{
	ll k,b;
	Data(void){}
	Data(ll _k,ll _b): k(_k), b(_b) {}
	inline ll get(ll x) const { return k * x + b;}
	inline Data operator + (const Data &oth) const { return Data(k + oth.k, b + oth.b);}
	inline Data operator * (const ll oth) const { return Data(k * oth, b * oth);}
	inline Data& operator += (const Data &oth){ return *this = *this + oth;}
};

struct Segment_Tree
{
	static const int MAXSIZ = (1<<18) * 2 + 5;
	Data sum[MAXSIZ], tag[MAXSIZ];
	int N;
	inline void build(int n){ for(N=1; N<n+2; N<<=1);}
	inline void add(int l,int r,Data k)
	{
		int xl=0, xr=0, x=1;
		for(l+=N-1, r+=N+1; l^r^1; l>>=1, r>>=1, x<<=1)
		{
			sum[l] += k * xl, sum[r] += k * xr;
			if(~l&1) sum[l^1] += k * x, tag[l^1] += k, xl += x;
			if( r&1) sum[r^1] += k * x, tag[r^1] += k, xr += x;
		}
		for(; l; l>>=1, r>>=1)
			sum[l] += k * xl, sum[r] += k * xr;
	}
	inline Data getsum(int l,int r) const
	{
		Data res(0,0);
		int xl=0, xr=0, x=1;
		for(l+=N-1, r+=N+1; l^r^1; l>>=1, r>>=1, x<<=1)
		{
			res += tag[l] * xl + tag[r] * xr;
			if(~l&1) res += sum[l^1], xl += x;
			if( r&1) res += sum[r^1], xr += x;
		}
		for(; l; l>>=1, r>>=1)
			res += tag[l] * xl + tag[r] * xr;
		return res;
	}
}tree;

int p[MAXN];
vector<pii> qs[MAXN];
ll res[MAXQ];

int main(void)
{
	int n = read(), Q = read();
	for(int i=1; i<=n; ++i) p[i] = read();
	for(int i=1; i<=Q; ++i)
	{
		int l = read(), r = read();
		qs[r].emplace_back(l, i);
	}
	
	static int ml[MAXN], mr[MAXN];
	stack<int> sta;
	for(int i=1; i<=n; ++i)
	{
		while(sta.size() && p[sta.top()] < p[i]) sta.pop();
		ml[i] = sta.size()? sta.top() + 1: 1;
		sta.push(i);
	}
	while(sta.size()) sta.pop();
	for(int i=n; i>=1; --i)
	{
		while(sta.size() && p[sta.top()] < p[i]) sta.pop();
		mr[i] = sta.size()? sta.top() - 1: n;
		sta.push(i);
	}
	
	static int pos[MAXN];
	static vector<pii> segs[MAXN];
	for(int i=1; i<=n; ++i) pos[p[i]] = i;
	for(int i=1; i<=n; ++i)
	{
		int x = p[i];
		for(int y=1; x*y<=n; ++y)
		{
			int l = pos[y], r = i;
			if(l >= r) continue;
			int mid = pos[x*y];
			if(l < ml[mid] || mr[mid] < r) continue;
			l = min(l, mid); r = max(r, mid);
			
			if(segs[mid].size() && l <= segs[mid].back().first)
				continue;
			segs[mid].emplace_back(l,r);
		}
	}
	
	static vector< tuple<int,int,int> > ops[MAXN];
	for(int i=1; i<=n; ++i)
	{
		const auto &vec = segs[i];
		if(!vec.size()) continue;
		for(int j=0; j<(int)vec.size(); ++j)
		{
			int xl = vec[j].second;
			int xr = j+1<(int)vec.size()? vec[j+1].second-1: mr[i];
			int yl = ml[i], yr = vec[j].first;
			if(xl > xr) continue;
			ops[xl].emplace_back(yl, yr, 1);
			ops[xr+1].emplace_back(yl, yr, -1);
		}
	}
	
	tree.build(n);
	for(int i=1; i<=n; ++i)
	{
		for(auto t: ops[i])
		{
			int l,r,k; tie(l,r,k) = t;
			tree.add(l, r, Data(k, (-i+1) * k));
		}
		for(auto t: qs[i])
		{
			int l = t.first, r = i, id = t.second;
			res[id] = tree.getsum(l,r).get(r);
		}
	}
	
	for(int i=1; i<=Q; ++i)
		write(res[i]), FastIO::pc('\n');
	FastIO::flush();
	return 0;
}