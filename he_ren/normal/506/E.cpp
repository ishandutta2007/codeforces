#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;
const int mod = 10007;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

inline vector<int> mul(const vector<int> &A,const vector<int> &B)
{
	if(!A.size() || !B.size()) return {};
	vector<int> res((int)A.size() + (int)B.size() - 1);
	for(int i=0; i<(int)A.size(); ++i)
		for(int j=0; j<(int)B.size(); ++j)
			res[i+j] = (res[i+j] + A[i] * B[j]) %mod;
	return res;
}

inline int linear_rec(vector<int> trans,vector<int> base,int m)
{
	int n = (int)trans.size();
	auto combine = [&] (const vector<int> &A,const vector<int> &B)
	{
		vector<int> res((int)A.size()+(int)B.size()-1);
		for(int i=0; i<(int)A.size(); ++i)
			for(int j=0; j<(int)B.size(); ++j)
				res[i+j] = (res[i+j] + A[i] * B[j]) %mod;
		for(int i=(int)res.size()-1; i>=n; --i)
			for(int j=0; j<n; ++j)
				res[i-j-1] = (res[i-j-1] + res[i] * trans[j]) %mod;
		res.resize(n);
		return res;
	};
	vector<int> res = {1}, a = {0,1};
	if(n == 1) a = {trans[0]};
	while(m)
	{
		if(m&1) res = combine(res,a);
		a = combine(a,a); m >>= 1;
	}
	res.resize(n); a.resize(n);
	
	int ans = 0;
	base.resize(n);
	for(int i=0; i<n; ++i)
		ans = (ans + res[i] * base[i]) %mod;
	return ans;
}

inline int getdiv(vector<int> A,vector<int> B,int m)
{
	ll iv = pw(B[0], mod-2);
	B.erase(B.begin());
	for(int &t: B) t = t * (mod - iv) %mod;
	for(int &t: A) t = t * iv %mod;
	
	if(A.size() < B.size()) A.resize(B.size());
	for(int i=0; i<(int)A.size(); ++i)
		for(int j=0; j<(int)B.size() && i-j-1>=0; ++j)
			A[i] = (A[i] + A[i-j-1] * B[j]) %mod;
	if(m<(int)A.size()) return A[m];
	
	m = m - (int)A.size() + (int)B.size();
	A.erase(A.begin(), A.end() - B.size());
	return linear_rec(B, A, m);
}

char s[MAXN];

int main(void)
{
	int d;
	scanf("%s%d",s+1,&d);
	int n = strlen(s+1);
	d += n;
	
	static int f[MAXN][MAXN][MAXN];
	f[0][0][0] = 1;
	for(int i=0; i<n; ++i)
		for(int j=0; i+j<n; ++j)
		{
			if(s[i+1] == s[n-j])
			{
				for(int k=n; k>=1; --k) f[i][j][k] = f[i][j][k-1];
				f[i][j][0] = 0;
			}
			for(int k=0; k<=n; ++k) if(f[i][j][k])
			{
				if(s[i+1] != s[n-j])
				{
					add_mod(f[i+1][j][k], f[i][j][k]);
					add_mod(f[i][j+1][k], f[i][j][k]);
				}
				else
				{
					add_mod(f[i+1][j+1][k], f[i][j][k]);
				}
			}
		}
	
	static vector<int> pw24[MAXN], pw25[MAXN];
	const int mx24 = n, mx25 = n/2+1;
	
	pw24[0] = pw25[0] = {1};
	for(int i=1; i<=mx24; ++i) pw24[i] = mul(pw24[i-1], {1, mod-24});
	for(int i=1; i<=mx25; ++i) pw25[i] = mul(pw25[i-1], {1, mod-25});
	
	vector<int> trans = mul(mul(pw24[mx24], pw25[mx25]), {1, mod-26});
	
	static int g[MAXN][MAXN];
	auto getpoly = [&] (int type)
	{
		vector<int> res;
		for(int i=0; i<=n; ++i)
			for(int j=0; j<=n; ++j) if(g[i][j])
			{
				auto cur = mul(pw25[mx25-i], pw24[mx24-j]);
				int delta = i+j-type;
				int mx = (int)cur.size() + delta;
				if((int)res.size() < mx) res.resize(mx);
				for(int k=0; k<(int)cur.size(); ++k)
					res[k+delta] = (res[k+delta] + cur[k] * g[i][j]) %mod;
			}
		return res;
	};
	
	for(int i=0; i<=n; ++i)
		for(int x=0; x<=n; ++x)
		{
			if(f[i][n-i][x])
				add_mod(g[x][n-2*x], f[i][n-i][x]);
			if(i!=0 && f[i][n-i+1][x])
				add_mod(g[x][n-2*x+1], f[i][n-i+1][x]);
		}
	auto P = getpoly(0);
	
	if(d&1)
	{
		for(int &t: P) t = t * 26 %mod;
		memset(g, 0, sizeof(g));
		for(int i=0; i<n; ++i)
			for(int x=0; x<=n; ++x)
			{
				if(f[i][n-i-1][x])
					add_mod(g[x][n-2*x+1], f[i][n-i-1][x]);
			}
		
		auto P2 = getpoly(1);
		P2 = mul(P2, {1, mod-26});
		if(P.size() < P2.size()) P.resize(P2.size());
		for(int i=0; i<(int)P2.size(); ++i)
			add_mod(P[i], P2[i]);
	}
	
	int ans = getdiv(P, trans, d/2);
	printf("%d",ans);
	return 0;
}