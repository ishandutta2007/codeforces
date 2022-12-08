#include <cstdio>
#include <cstring>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MOD = 1e9 + 7;

struct mint
{
public:
	int v;
	mint(int init = 0) : v(init)
	{
		if(v < 0){v = ti((v+tl(MOD)*16)%MOD);}
		if(MOD <= v) {v %= MOD;}
	}
	operator int () const {return v;}
	mint operator + (mint o)const {return mint(v+o.v<MOD?v+o.v:v+o.v-MOD);}
	mint operator - (mint o)const {return mint(o.v<=v?v-o.v:v-o.v+MOD);}
	mint operator * (mint o)const {return mint(ti(tl(v)*o.v%MOD));}

	void operator += (mint o) {v = (v+o.v<MOD?v+o.v:v+o.v-MOD);}
	void operator *= (mint o) {v = ti(tl(v)*o.v%MOD);}
};

const int MN = 62;
const int ME = MN*MN;
const int MX = 15;
mint ch[MN][MN];
void pcp()
{
	for(int i = 0;i < MN;++i)
	{
		ch[i][0] = ch[i][i] = mint(1);
		for(int j = 1;j < i;++j)
			ch[i][j] = ch[i-1][j] + ch[i-1][j-1];
	}
}

mint dp[MN][1<<MX];
int cover[MN], cnt[MX][1<<MX];
int b[MX], B;
int c[MN], C;
mint solve()
{
	memset(dp, 0, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0;i < C;++i)
	{
		cover[i] = 0;
		for(int j = 0;j < B;++j)
			if(!(c[i]%b[j]))
				cover[i] |= 1<<j;
		++cnt[B][cover[i]];
	}
	for(int i = B-1;i >= 0;--i)
		for(int j = 0;j < 1<<B;++j)
		{
			cnt[i][j] = cnt[i+1][j];
			if(j&1<<i)
				cnt[i][j] += cnt[i+1][j^1<<i];
		}
	for(int i = 0;i < C;++i)
		dp[1][cover[i]] += mint(1);
	for(int i = 1;i < C;++i)
		for(int j = 1;j < 1<<B;++j)
		{
			for(int k = 0;k < C;++k)
				if(cover[k]&j && (cover[k]&j) != cover[k])
					dp[i+1][j|cover[k]] += dp[i][j];
			dp[i+1][j] += dp[i][j] * mint(cnt[0][j] - i);
		}
	return dp[C][(1<<B)-1];
}

int N;
int a[MN];
int deg[MN];
int hd[ME], to[ME], nx[ME], E;
void adde(int a, int b)
{
	nx[E] = hd[a];
	to[E] = b;
	hd[a] = E++;
}
bool vis[MN];
int cur;
mint ans;

void dfs(int n)
{
	vis[n] = 1;
	if(deg[n]) c[C++] = a[n];
	else b[B++] = a[n];
	for(int x = hd[n];~x;x = nx[x])
		if(!vis[to[x]])
			dfs(to[x]);
}

int main(void)
{
	pcp();
	scanf("%d", &N);
	for(int i = 0;i < N;++i)
		scanf("%d", a+i);
	memset(hd, -1, sizeof(hd));
	for(int i = 0;i < N;++i)
		for(int j = 0;j < N;++j)
		{
			if(i == j) continue;
			if(a[i]%a[j] == 0)
			{
				++deg[i];
				adde(i, j);
				adde(j, i);
			}
		}

	ans = mint(1);
	for(int i = 0;i < N;++i)
		if(!vis[i])
		{
			B = C = 0;
			dfs(i);
			if(C)
			{
				ans *= solve() * ch[cur+C-1][cur];
				cur += C-1;
			}
		}
	
	printf("%d\n", ti(ans));
	return 0;
}