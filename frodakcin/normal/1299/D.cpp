#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int MOD = 1e9 + 7;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
struct mint
{
public:
	int val;
	mint(int _val = 0) : val(_val)
	{
		val = (-MOD <= val && val < MOD) ? val : val%MOD;
		if(val < 0) val += MOD;
	}
	explicit operator int () const {return val;}
	explicit operator bool () const {return val;}

	mint operator -() const {return mint(-val);}
	mint& operator += (mint m) {if((val += m.val) >= MOD) val -= MOD; return *this;}
	mint& operator -= (mint m) {if((val -= m.val) < 0) val += MOD; return *this;}
	mint& operator *= (mint m) {val = ti(tl(val)*m.val%MOD); return *this;}

	friend mint pow(mint a, int p)
	{
		mint r(1);
		for(;p;p>>=1, a*=a) if(p&1) r*=a;
		return r;
	}

	friend mint operator + (mint a, mint b) {return a += b;}
	friend mint operator - (mint a, mint b) {return a -= b;}
	friend mint operator * (mint a, mint b) {return a *= b;}
};

const int MN = 1e5 +100;
const int MB = 5;
using uint = unsigned int;
int N, M;

std::vector<uint> all;

uint cur;
uint merge(uint v, int x)
{
	if(v & 1<<x) return 0;
	for(uint pcur = v;pcur;pcur &= pcur-1)
		v |= (uint)1<<(__builtin_ctz(pcur)^x);
	return v;
}
uint merge2(uint v, uint x)
{
	int k;
	for(uint pcur = x;pcur;pcur &= pcur-1)
	{
		k = __builtin_ctz(pcur);
		if(!(v&1<<k))
			v = merge(v, k);
	}
	return v;
}
int combine[400][400];
void brute(int n = 0)
{
	all.push_back(cur);
	if(n == MB)
		return;
	for(uint i = 1;i < 1<<MB;++i)
	{
		if(cur&(uint)1<<i)
			break;
		uint pcur = cur;
		cur = merge(cur, i);
		brute(n+1);
		cur = pcur;
	}
}
struct E
{
public:
	int n, w;
};
std::vector<E> a[MN];
void adde(int u, int v, int w)
{
	a[u].push_back({v, w});
	a[v].push_back({u, w});
}

struct Group
{
public:
	int a, b;
	int spec;
};
std::vector<Group> groups;
std::vector<uint> mod[MN];
bool vis[MN];
int d[MN];
void dfs(int n = 1, int p = 0)
{
	//printf("DURING DFS: %d: %d (par = %d, dpar = %d, edge = %d)\n", n, d[n], p, d[p], d[n]^d[p]);
	vis[n] = 1;
	if(!p)
	{
		for(E x : a[n])
			if(!vis[x.n])
			{
				groups.push_back({x.n, -1, -1});
				d[x.n] = x.w;
				dfs(x.n, 1);
			}
	}
	else
		for(E x : a[n])
			if(x.n != p)
			{
				//printf("TO EDGE %d -> %d\n", n, x.n);
				if(x.n == 1)
					groups.back().b = n, groups.back().spec = x.w;
				else if(vis[x.n])
				{
					if(n < x.n)
						mod[groups.size()-1].push_back(d[n]^d[x.n]^x.w);
					//printf("MODVAL %d %d %d\n", n, x.n, d[n]^d[x.n]^x.w);
				}
				else
					d[x.n] = d[n] ^ x.w, dfs(x.n, n);
			}
}
int G;
mint dp[2][400];
int main(void)
{
	cur = 1;
	brute();
	std::sort(all.begin(), all.end());
	all.resize(std::unique(all.begin(), all.end()) - all.begin());
	for(int i = 0;i < all.size();++i)
		for(int j = 0;j < all.size();++j)
			combine[i][j] = (all[i]&all[j]) == 1 ? std::distance(all.begin(), std::lower_bound(all.begin(), all.end(), merge2(all[i], all[j]))) : -1;
	//printf("ALL SIZE %d\n", all.size());
	scanf("%d%d", &N, &M);
	for(int i = 0, u, v, w;i < M;++i)
		scanf("%d%d%d", &u, &v, &w), adde(u, v, w);

	dfs();
	G = groups.size();

	//for(int i = 1;i <= N;++i) printf("D VAL %d: %d\n", i, d[i]);

	{
		uint v;
		bool cr = 0;
		dp[cr][0] = mint(1);
		for(int i = 0;i < G;++i, cr^=1)
		{
			if(!~groups[i].b)
			{
				uint v = 1;
				for(int x : mod[i])
				{
					v = merge(v, x);
					//printf("POSS %d %d\n", i, v);
				}
				int z = std::distance(all.begin(), std::lower_bound(all.begin(), all.end(), v));
				memcpy(dp[!cr], dp[cr], sizeof(dp[0]));
				for(int j = 0;j < all.size();++j)
					if(dp[cr][j])
						if((v & all[j]) == 1)
							dp[!cr][combine[z][j]] += dp[cr][j];
			}
			else
			{
				uint c[2];
				int z[2];
				c[0] = 1;
				for(int x : mod[i])
					c[0] = merge(c[0], x);
				c[1] = merge(c[0], groups[i].spec ^ d[groups[i].b]);

				z[0] = std::distance(all.begin(), std::lower_bound(all.begin(), all.end(), c[0]));
				z[1] = std::distance(all.begin(), std::lower_bound(all.begin(), all.end(), c[1]));
				//printf("HMM %d %d\n", c[0], c[1]);

				memcpy(dp[!cr], dp[cr], sizeof(dp[0]));
				for(int j = 0;j < all.size();++j)
					if(dp[cr][j])
					{
						//printf("TESTCMB %d %d\n", combine[z[0]][j], combine[z[1]][j]);
						if((c[0] & all[j]) == 1)// must do this check, and not if combine is -1
							dp[!cr][combine[z[0]][j]] += 2*dp[cr][j];
						if((c[1] & all[j]) == 1)
							dp[!cr][combine[z[1]][j]] += dp[cr][j];
					}
			}
		}
		mint ans(0);
		for(int i = 0;i < all.size();++i)
		{
			ans += dp[cr][i];
			//if(dp[cr][i]) printf("DPV %d (%u) %d\n", i, all[i], dp[cr][i]);
		}
		printf("%d\n", ans);
	}

	return 0;
}