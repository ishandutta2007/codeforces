#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

struct Matrix
{
	static int N;
	int a[MAXN * 2][MAXN * 2];
	Matrix(void){ clear();}
	void clear(void){ memset(a, 0, sizeof(a));}
	void to_unit(void)
	{
		clear();
		for(int i=1; i<=N; ++i) a[i][i] = 1;
	}
	int* operator [] (int x){ return a[x];}
	const int* operator [] (int x) const { return a[x];}
	friend Matrix operator * (const Matrix &a,const Matrix &b)
	{
		static Matrix res;
		res.clear();
		for(int k=1; k<=N; ++k)
			for(int i=1; i<=N; ++i)
				for(int j=1; j<=N; ++j)
					res.a[i][j] = (res.a[i][j] + (ll)a.a[i][k] * b.a[k][j]) %mod;
		return res;
	}
};
int Matrix::N;

Matrix pw(Matrix a,int b)
{
	Matrix res; res.to_unit();
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a; b>>=1;
	}
	return res;
}

bool hase[MAXN][MAXN];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		hase[u][v] = hase[v][u] = 1;
	}
	
	Matrix::N = 2 * n;
	
	Matrix a,b;
	for(int i=1; i<=n; ++i)
	{
		a[2*i-1][2*i-0] = 1;
		a[2*i-0][2*i-1] = 1;
	}
	for(int u=1; u<=n; ++u)
		for(int v=1; v<=n; ++v) if(hase[u][v])
		{
			add_mod(b[2*u-0][2*u-1], mod - 1);
			add_mod(b[2*u-0][2*v-0], 1);
		}
	
	for(int i=1; i<=2*n; ++i)
		for(int j=1; j<=2*n; ++j)
			add_mod(a[i][j], b[i][j]);
	
	auto ans = b * pw(a, d-1);
	int sum = 0;
	for(int i=1; i<=n; ++i)
		add_mod(sum, ans[2*i-0][2*i-0]);
	printf("%d",sum);
	return 0;
}