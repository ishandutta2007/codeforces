#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e4 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct Line
{
	ll k,b;
	Line(void){}
	Line(ll _k,ll _b): k(_k), b(_b) {}
	ll get(ll x) const { return k * x + b;}
};

struct Convex_Hull
{
	vector<Line> q;
	int hd, tl;
	Convex_Hull(int siz=0): q(siz), hd(0), tl(-1) {}
	void clear(void){ hd = 0; tl = -1;}
	void push_back(Line p)
	{
		if(hd<=tl && q[tl].k == p.k)
		{
			if(q[tl].b <= p.b) return;
			else --tl;
		}
		while(hd+1<=tl
			&& (__int128)(p.b - q[tl-1].b) * (q[tl-1].k - q[tl].k)
			<= (__int128)(q[tl].b - q[tl-1].b) * (q[tl-1].k - p.k)
		) --tl;
		if(++tl >= (int)q.size()) q.push_back(p);
		else q[tl] = p;
	}
	ll get(ll x)
	{
		if(hd>tl) return linf;
		while(hd+1<=tl && q[tl-1].get(x) <= q[tl].get(x)) --tl;
		return q[tl].get(x);
	}
};

int a[MAXN];
ll dp[2][MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	int now = 0;
	for(int k=1; k<=d; ++k)
	{
		now ^= 1;
		memset(dp[now], 0x3f, sizeof(dp[now]));
		auto trans = [&] (int l,int mid,int r)
		{
			l = max(l, k-1); r = min(r, n);
			if(mid < l || mid >= r) return;
			
			static int mx[MAXN];
			mx[mid] = mx[mid+1] = a[mid+1];
			for(int i=mid-1; i>=l; --i)
				mx[i] = max(mx[i+1], a[i+1]);
			for(int i=mid+2; i<=r; ++i)
				mx[i] = max(mx[i-1], a[i]);
			
			static Convex_Hull conv(n);
			
			conv.clear();
			for(int i=r, j=l; i>=mid+1; --i)
			{
				for(; j<=mid && mx[j] >= mx[i]; ++j)
					if(dp[now^1][j] < linf)
						conv.push_back(Line(mx[j], dp[now^1][j] - (ll)j * mx[j]));
				dp[now][i] = min(dp[now][i], conv.get(i));
			}
			
			conv.clear();
			for(int i=mid+1, j=mid; i<=r; ++i)
			{
				for(; j>=l && mx[i] >= mx[j]; --j)
					if(dp[now^1][j] < linf)
						conv.push_back(Line(j, dp[now^1][j]));
				dp[now][i] = min(dp[now][i], conv.get(-mx[i]) + (ll)i * mx[i]);
			}
		};
		
		for(int i=1; i<=n; i<<=1)
			for(int j=k-1; j+i<=n; j+=i<<1)
				trans(j, j+i-1, j+(i<<1)-1);
	}
	
	printf("%lld",dp[now][n]);
	return 0;
}