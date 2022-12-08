#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <string>

using ll = long long;

const int MOD = 998244353;
const int MN = 1e5+10;
const int MM = 1e5+10;
const int MB = 17;

struct mint
{
	public:
		int val;

		mint(): val() {}
		template<typename T>
		mint(T v)
		{
			if(v < -MOD || MOD <= v) v%=MOD;
			if(v<0) v+=MOD;
			val = (int)v;
		}

		mint& operator += (const mint& o) {if((val+=o.val)>=MOD) val-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((val-=o.val)<0) val+=MOD; return *this;}
		mint& operator *= (const mint& o) {val=(ll)val*o.val%MOD; return *this;}

		friend mint operator + (mint a, const mint& b) {return a+=b;}
		friend mint operator - (mint a, const mint& b) {return a-=b;}
		friend mint operator * (mint a, const mint& b) {return a*=b;}

		template<typename T>
		friend mint pow(mint b, T p)
		{
			mint f(1);
			for(;p;p>>=1, b*=b)
				if(p&1)
					f*=b;
			return f;
		}
};

using poly = std::vector<mint>;

void fwht(poly& a)
{
	int L=__builtin_ctz(a.size()); // should be equal to 31 - __builtin_clz(a.size());
	assert(L == 31 - __builtin_clz(a.size()));

	for(int i=0;i<L;++i)
		for(int j=0;j<1<<L;j+=1<<i+1)
			for(int k=0;k<1<<i;++k)
			{
				mint v=a[j|1<<i|k];
				a[j|1<<i|k] = a[j|k]-v;
				a[j|k] += v;
			}
}

int N, M, v[MN];
std::vector<int> a[MN];

void dfs(int n)
{
	std::vector<char> ok(a[n].size(), 0);
	for(int x:a[n])
	{
		if(v[x]==-1)
			dfs(x);
		if(v[x]<ok.size()) ok[v[x]]=1;
	}
	v[n]=0;
	for(;v[n]<ok.size() && ok[v[n]];)
		++v[n];
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0;i<M;++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		a[u].push_back(v);
	}

	memset(v, -1, sizeof v);
	for(int i=1;i<=N;++i)
		if(v[i]==-1) dfs(i);

	//for(int i=1;i<=N;++i) printf("gr of %d: %d\n", i, v[i]);
	
	poly ans(1<<MB);
	mint inv3 = pow(mint(3), MOD-2);
	mint invn = pow(mint(N), MOD-2);
	mint invn1 = pow(mint(N+1), MOD-2);
	for(int i=1;i<=N;++i)
		ans[v[i]] += invn;
	fwht(ans);

	for(int i=0;i<1<<MB;++i)
	{
		// 1/(n+1) * \sum {(n/(n+1)*v[i])^i}
		ans[i] = invn1 * pow(mint(1)-mint(N)*invn1*ans[i], MOD-2);
	}

	fwht(ans);
	mint dif=pow(mint((int)ans.size()), MOD-2);
	printf("%d\n", (mint(1)-ans[0]*dif).val);
	return 0;
}