#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

using ll = long long;

const int MN = 42;
const int MP = 1500;
const int MOD = 1e9+7;

struct mint
{
	public:
		int v;
		mint(int _v=0): v(_v)
		{
			if(-v < MOD || MOD <= v) v %= MOD;
			if(v < 0) v += MOD;
		}
		template<typename T> mint(T _v)
		{
			if(-_v < MOD || MOD <= _v) v=_v%MOD;
			else v=_v;
			if(v<0) v+=MOD;
		}

		mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
		mint& operator *= (const mint& o) {v=(ll)v*o.v%MOD; return *this;}

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

int N, p[MN];
std::vector<int> unq, cnt;

std::vector<int> get_map(int v)
{
	std::vector<int> f(unq.size());
	for(int i=0;i<unq.size();++i)
	{
		f[i]=v%(cnt[i]+1);
		v/=cnt[i]+1;
	}
	return f;
}

int get_state(const std::vector<int>& map)
{
	int v=0;
	int mul=1;
	for(int i=0;i<unq.size();++i)
	{
		v += map[i] * mul;
		mul *= cnt[i]+1;
	}
	return v;
}

mint inv[MN], F[2][MN];
mint ways[MN]; // ways[i] = permutation, i numbers just be after 1, rest can be anywhere
mint dp[MP][MN][MN][MN];

void pcpmod()
{
	inv[1]=mint(1);
	for(int i=2;i<=N;++i)
		inv[i] = mint(MOD-MOD/i)*inv[MOD%i];

	F[0][0]=F[1][0]=mint(1);
	for(int i=1;i<=N;++i)
		F[0][i]=mint(i)*F[0][i-1], F[1][i]=F[1][i-1]*inv[i];
}

mint choose(int n, int k)
{
	assert(0 <= k && k <= n && n <= N);
	return F[0][n]*F[1][n-k]*F[1][k];
}

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i) scanf("%d", p+i), --p[i];

	pcpmod();

	// init ways
	for(int i=0;i<N;++i)
		for(int j=i;j<N;++j)
			ways[i] += F[0][j] * F[0][N-j-1] * choose(N-i-1, j-i);

	{ // build cyc
		std::vector<int> cyc;
		std::vector<char> vis(N, 0);
		for(int i=0;i<N;++i)
			if(!vis[i])
			{
				int c=0;
				for(int n=i;;n=p[n])
				{
					if(vis[n]) break;
					vis[n]=1;
					++c;
				}
				cyc.push_back(c);
			}
		std::sort(cyc.begin(), cyc.end());
		for(int &x:cyc)
			if(unq.empty() || x != unq.back())
				unq.push_back(x), cnt.push_back(1);
			else
				++cnt.back();
	}

	int tot=1;
	for(int &x:cnt) tot*=x+1;

	dp[0][0][0][0]=mint(1);
	for(int m=0;m<tot;++m)
	{
		std::vector<int> map = get_map(m);
		int used=0;
		for(int i=0;i<unq.size();++i)
			used += map[i]*unq[i];

		for(int i=0;i<=N;++i)
			for(int j=1;j<=N;++j)
				for(int k=0;k<=unq.size();++k)
					dp[m][j][0][0] += dp[m][i][j][k];
		for(int i=0;i<=N;++i)
			for(int j=0;j<=N;++j)
				for(int k=0;k<unq.size();++k)
					if(dp[m][i][j][k].v)
					{
						assert(i > 0 || used == j);
						mint mul = pow(ways[N-(used-j)-1], unq[k]);
						if(i>0) mul -= pow(ways[N-(used-j-i)-1], unq[k]);

						for(int l=cnt[k]-map[k];l>=0;--l) //build l cycles k
						{
							map[k] += l;
							dp[get_state(map)][i][j+unq[k]*l][k+1] += dp[m][i][j][k] * pow(mul, l) * choose(map[k], l);
							map[k] -= l;
						}
					}
	}

	//ans: dp[tot-1][...][0][0]
	mint ans;
	for(int i=1;i<=N;++i)
		ans += dp[tot-1][i][0][0];
	printf("%d\n", ans.v);
	return 0;
}