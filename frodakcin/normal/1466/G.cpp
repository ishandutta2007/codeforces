/*
 - All strings <= 1e6 characters, and the first one larger, L memory
 - Solve all of these smaller strings [count substr occurrence] with trie, L memory, run it K times
 - Solve larger strings with KMP (26 times each, for each possible join character) + prefix sum, L memory. Probably will use aho instead of constructing KMP
*/

#include <cstdio>
#include <cstring>
#include <cassert>
#include <queue>
#include <vector>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MOD = 1e9+7;
const int ML = 1e6+10; // reduced for testing purposes
const int MN = 1e5+10; // same as max Q
const int MC = 26;

struct mint
{
	public:
		int v;
		mint(): v(0) {}
		template<typename T> mint(T _v)
		{
			if(_v < MOD || MOD <= _v) _v %= MOD;
			v = (int)_v;
			if(v<0) v += MOD;
		}

		operator int() {return v;}

		mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
		mint& operator *= (const mint& o) {v=(ll)v*o.v%MOD; return *this;}

		friend mint operator + (mint a, const mint& b) {return a+=b;}
		friend mint operator - (mint a, const mint& b) {return a-=b;}
		friend mint operator * (mint a, const mint& b) {return a*=b;}
};

namespace T // TRIE
{
	int c[ML][MC], l[ML], X, pre[ML], post[ML], ctr;
	std::vector<int> down[ML];
	void init()
	{
		X=0;
		memset(c, -1, sizeof c);
		l[0]=-1;
		ctr=0;
	}
	int add(const char *s, const int& L)
	{
		int n=0;
		for(int i=0;i<L;++i)
		{
			if(c[n][s[i]] == -1)
			{
				c[n][s[i]]=++X;
				//printf("%d -> %d (%d)\n", n, X, s[i]);
			}
			n=c[n][s[i]];
		}
		return n;
	}
	int go(int n, int i)
	{
		for(;n!=-1;n=l[n])
			if(c[n][i] != -1)
				return c[n][i];
		return 0;
	}
	void dfs(int n=0)
	{
		pre[n] = ctr++;
		for(int x:down[n])
			dfs(x);
		post[n] = ctr;
	}
	void build()
	{
		std::queue<int> q; q.push(0);
		for(int n;!q.empty();q.pop())
		{
			n=q.front();
			if(l[n] != -1)
				down[l[n]].push_back(n);
			//printf("%d links to %d\n", n, l[n]);
			for(int i=0;i<MC;++i)
				if(c[n][i] != -1)
				{
					l[c[n][i]] = go(l[n], i);
					q.push(c[n][i]);
				}
		}
		dfs();
		assert(ctr == X+1);
	}
}

int N, Q, k[MN], a[MN], b[MN], mlen, C, s0, sc, p[ML], f[MN];
// C: [0..C] directly computed, (C..) bulk computed using C as prefix/suffix
char s[ML*2], t[MN], w[ML];
mint m[MN][MC], p2[MN];
std::vector<int> q[30];

int main()
{
	p2[0]=mint(1);
	for(int i=0;i+1<MN;++i)
		p2[i+1]=p2[i]*mint(2);

	scanf("%d%d", &N, &Q);
	scanf(" %s", s);
	s0 = strlen(s);
	for(int i=0;s[i];++i) s[i]-='a';
	scanf(" %s", t);
	for(int i=0;t[i];++i) t[i]-='a';
	T::init();
	for(int i=0;i<Q;++i)
	{
		scanf(" %d", k+i);
		scanf(" %s", w+a[i]);
		for(a[i+1]=a[i];w[a[i+1]];++a[i+1]) w[a[i+1]]-='a';
		ckmax(mlen, a[i+1]-a[i]);
		b[i] = T::add(w+a[i], a[i+1]-a[i]);
	}
	T::build();

	for(sc=s0;sc<mlen && C < N;sc=sc*2+1, ++C)
	{
		s[sc]=t[C];
		memcpy(s+sc+1, s, sc*sizeof*s);
	}
	//printf("%d (%d)\n", C, sc);
	for(int i=C;i<N;++i)
	{
		for(int j=0;j<MC;++j)
			m[i+1][j]=m[i][j]*mint(2);
		m[i+1][t[i]]+=mint(1);
	}

	//Solve all small strings
	for(int i=0;i<Q;++i)
		if(k[i]<=C)
			q[k[i]].push_back(i);
	for(int i=0, sl=s0;i<=C;++i, sl=sl*2+1)
	{
		if(i<C && q[i].empty()) continue;
		memset(p, 0, (T::X+2)*sizeof*p);
		for(int j=0, n=0;j<sl;++j)
		{
			n = T::go(n, s[j]);
			++p[T::pre[n]+1];
			//printf("%d %d\n", i, T::pre[n]);
		}
		for(int j=0;j<=T::X;++j)
			p[j+1]+=p[j];
		for(int x:q[i])
			f[x] = p[T::post[b[x]]]-p[T::pre[b[x]]];
	}

	//Solve all large strings. Note that p still stores the answer to s_C
	for(int i=0;i<Q;++i)
		if(k[i]>C)
		{
			mint v=mint(p[T::post[b[i]]]-p[T::pre[b[i]]])*p2[k[i]-C];
			int L = a[i+1]-a[i], nl=0;
			for(int j=0;j<L;++j)
				nl=T::go(nl, s[sc-L+j]);

			auto test = [&](int n){return T::pre[b[i]] <= T::pre[n] && T::post[n] <= T::post[b[i]];};
			for(int x=0;x<MC;++x) // try each char
			{
				int n=T::go(nl, x);
				int occ=0;
				for(int i=0;i<L;++i)
				{
					occ += test(n);
					n = T::go(n, s[i]);
				}
				v += mint(occ)*m[k[i]][x];
			}
			f[i]=v;
		}

	for(int i=0;i<Q;++i)
		printf("%d\n", f[i]);
	return 0;
}