#include<cstdio>
#include<cstring>
#include<iostream>
typedef long long ll;
const int MAXN = 100 + 5;
const int mod = 1e9 + 7;
using namespace std;

int n;
ll a[MAXN];

struct Matrix
{
	ll g[MAXN][MAXN];
	Matrix(){ memset(g,0,sizeof(g));}
	inline void mul(Matrix &b)
	{
		Matrix c;
		for(int k=1; k<=n; ++k)
			for(int i=1; i<=n; ++i)
				for(int j=1; j<=n; ++j)
					c.g[i][j] += g[i][k]*b.g[k][j] %mod;
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				c.g[i][j]%=mod;
		*this=c;
	}
}t,ans;

inline void pw(ll b)
{
	for(int i=1; i<=n; ++i) ans.g[i][i]=1;
	
	while(b)
	{
		if(b&1) ans.mul(t);
		t.mul(t);
		b>>=1;
	}
}

#define lowbit(x) ((x)&-(x))
inline int count(ll x)
{
	int res=0;
	while(x)
		x^=lowbit(x), ++res;
	return res;
}

int main(void)
{
	ll k;
	cin>>n>>k;
	for(int i=1; i<=n; ++i) cin>>a[i];
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			t.g[i][j] = (count(a[i]^a[j])%3 == 0);
	
	pw(k-1);
	int res=0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			res = (res+ans.g[i][j]) %mod;
	
	cout<<res;
	return 0;
}