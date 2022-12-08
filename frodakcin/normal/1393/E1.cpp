//FUCK E2

//atrocious time and memory constraints >:(
//This solution is literally LINEAR in time and memory (technically (L+N) log K, but 26 is constant). Fuck this.
#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MOD = 1e9+7;
const int INF = 1e7;
const int MN = 1e3+1;
const int LG = 30;
const int MS = 2e5+LG+1;

struct mint
{
	public:
		int v;
		mint(int v=0):v(v){}
		mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
		mint& operator *= (const mint& o) {v=(int)((ll)v*o.v%MOD); return *this;}

		friend mint operator + (mint a, const mint& b) {return a+=b;}
		friend mint operator - (mint a, const mint& b) {return a-=b;}
		friend mint operator * (mint a, const mint& b) {return a*=b;}

		explicit operator int() const {return v;}
};

mint dp[MS+MN], f;
int N, S, B, a[MN], sa[MS], isa[MS], lcp[MS], rmq[LG][MS/LG], mask[MS], o[MS], nx[MS], d[MS*2], l[MS*2], X, hd[MS*2], dw[MS*2], all[LG+1], q[LG], Q;
char s[MS], u[MS*2];
std::map<char, int> c[MS*2];

int append(int p, char x)
{
	std::map<char, int>::iterator it;
	int n=++X;
	d[n]=d[p]+1;
	for(;~p&&(it=c[p].find(x))==c[p].end();p=l[p]) c[p].insert({x, n});
	if(!~p) l[n]=0;
	else
	{
		int q=it->second;
		if(d[q]==d[p]+1) l[n]=q;
		else
		{
			++X;
			l[X]=l[q], d[X]=d[p]+1, c[X]=c[q];
			l[n]=l[q]=X;
			for(;~p&&(it=c[p].find(x))->second==q;p=l[p]) it->second=X;
		}
	}
	return n;
}

void adde(int a, int b)
{
	nx[b]=hd[a];
	hd[a]=b;
}

void dfs(int n=0)
{
	int c=0;
	int *k = dw+(1+dw[0]);
	for(int i=hd[n];~i;i=nx[i])
		k[c++]=i;
	dw[0]+=c;
	if(c)
	{
		std::sort(k, k+c, [](int x, int y){return u[x]<u[y];});
		//for(int i=0;i<dw[n].size();++i) printf("%c", u[dw[n][i]]); printf("\n");
		for(int i=0;i<c;++i)
			dfs(k[i]);
	}
	else
		sa[X++]=S-d[n];
}

void build_sa_psuedolinear()
{
	l[0]=-1;
	for(int i=S-1,n=0;i>=0;--i)
		n=append(n, s[i]);
	memset(hd, -1, 2*S*sizeof*hd);
	for(int i=1;i<=X;++i)
		adde(l[i], i);
	u[0]=-1;
	for(int i=S-1,n=0,x,p,r;i>=0;--i)
	{
		n=c[n][s[i]];
		x=n;
		r=S;
		for(;!u[x];x=p)
		{
			p=::l[x];
			//add {x, r-d[x]+d[p], r}
			r-=d[x]-d[p];
			u[x]=s[r];
		}
	}
	X=0;//don't need anymore
	dfs();
}

void build_lcp()
{
	for(int i=0;i<S;++i)
		isa[sa[i]]=i;
	for(int i=0,p=0;i<S;++i)
		if(isa[i]==S-1) p=0;
		else
		{
			for(;s[i+p]==s[sa[isa[i]+1]+p];++p);//should deal with out of bounds automatically
			lcp[isa[i]]=p;
			if(p)--p;
		}
	B=S/LG;
	for(int i=0;i<=B;++i)
	{
		rmq[0][i]=INF;
		Q=0;
		for(int j=0,m=0;j<LG;++j)//will overflow, but not by more than LG, and it shouldn't impact queries in any way
		{
			ckmin(rmq[0][i], lcp[i*LG+j]);
			for(;Q&&lcp[i*LG+j]<=lcp[i*LG+q[Q-1]];) m^=1<<q[--Q];
			q[Q++]=j, m|=1<<j;
			mask[i*LG+j+1]=m;
		}
	}
	for(int i=B;i>=0;--i)
		for(int j=0;i+(1<<j+1)<=B+1;++j)
			rmq[j+1][i]=std::min(rmq[j][i], rmq[j][i+(1<<j)]);
}

int get_lcp_small(int rm, int v)//not used, but here for my own reference
{
	return lcp[v/LG*LG+__builtin_ctz(mask[v]&~all[rm])];
}
int get_lcp(int u, int v)
{
	u=isa[u], v=isa[v];
	if(u==v) return INF;
	if(v<u) std::swap(u,v);
	int u2=u/LG+1, v2=v/LG, f=INF;
	if(v2<u2) return lcp[v2*LG+__builtin_ctz(mask[v]&~all[u-v2*LG])];
	if(u2<v2)
	{
		int d=31-__builtin_clz(v2-u2);
		f=std::min(rmq[d][u2], rmq[d][v2-(1<<d)]);
	}
	ckmin(f, lcp[(u2-1)*LG+__builtin_ctz(mask[u2*LG]&~all[u-(u2-1)*LG])]);
	if(v2*LG<v) ckmin(f, lcp[v2*LG+__builtin_ctz(mask[v])]);

	/*
	int fv=INF;
	for(int i=u;i<v;++i) ckmin(fv, lcp[i]);
	//printf("%d %d\n", fv, f);
	assert(fv==f);
	*/
	return f;
}

struct SubStr
{
	public:
		int i, l;
};
struct Multi
{
	public:
		std::vector<SubStr> v;
		Multi() {v.reserve(2);}
		void add(int i, int j){if(i<j) v.push_back({i,j-i});}//[i,j)
		bool operator < (const Multi& o) const
		{
			int i=0,j=0,x=0,y=0;//x,y=offsets
			for(;i<v.size()&&j<o.v.size();)
			{
				int l=std::min({get_lcp(v[i].i+x, o.v[j].i+y), v[i].l-x, o.v[j].l-y});
				if(l < v[i].l-x && l < o.v[j].l-y)
					return s[v[i].i+x+l]<s[o.v[j].i+y+l];
				if((x+=l)>=v[i].l) ++i, x=0;
				if((y+=l)>=o.v[j].l) ++j, y=0;
			}
			return (i<v.size()) < (j<o.v.size());
		}
};
Multi val[MS+MN];

int main()
{
	for(int i=0;i<=LG;++i)
		all[i]=(1<<i)-1;
	scanf("%d", &N);
	for(int i=0;i<N;++i)
	{
		scanf(" %s", s+a[i]);
		for(a[i+1]=a[i]+1;s[a[i+1]];++a[i+1]);
	}
	S=a[N];
	s[S++]='a'-1;
	//printf("%s\n", s);
	build_sa_psuedolinear();
	build_lcp();
	//for(int i=0;i<S;++i) printf("%2d: %3d %3d %s\n", i, sa[i], rmq[0][i], s+sa[i]);
	for(int i=0;i<N;++i)
	{
		val[a[i+1]+i].add(a[i], a[i+1]);
		for(int j=a[i];j<a[i+1];++j)
		{
			val[j+i].add(a[i], j);
			val[j+i].add(j+1, a[i+1]);
		}
		{
			int st=a[i]+i, en=a[i+1]+i+1;
			nx[a[i+1]-1]=a[i+1];
			for(int j=a[i+1]-2;j>=a[i];--j)
				nx[j]=s[j]==s[j+1]?nx[j+1]:j+1;
			for(int j=a[i];j<a[i+1];++j)
				if(nx[j]<a[i+1]&&s[j]<s[nx[j]])
					o[--en]=j+i;
				else
					o[st++]=j+i;
			o[st]=a[i+1]+i;
		}
		if(i)
		{
			mint p(0);
			int j=a[i-1]+i-1;
			for(int k=a[i]+i;k<a[i+1]+i+1;++k)
			{
				for(;j<a[i]+i&&!(val[o[k]]<val[o[j]]);++j) p+=dp[j];//we can let dp correspond to proper ordering
				dp[k]=p;
			}
		}
		else
			for(int i=0;i<a[1]+1;++i)
				dp[i]=mint(1);
	}
	//for(int i=0;i<S;++i) printf("%d ", o[i]); printf("\n");
	for(int i=a[N-1]+N-1;i<a[N]+N;++i)
		f+=dp[i];
	printf("%d\n", f);
	return 0;
}