#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const ldb eps = 1e-9;

inline int sgn(ldb x){ return x < -eps? -1: x > eps? 1: 0;}

struct Matrix
{
	vector< vector<ldb> > a;
	Matrix(int _n = 0): a(_n, vector<ldb>(_n)) {}
	void to_unit(void){ for(int i=0; i<(int)a.size(); ++i) a[i][i] = 1;}
	inline int size(void) const { return a.size();}
	vector<ldb>& operator [] (int x){ return a[x];}
	const vector<ldb>& operator [] (int x) const { return a[x];}
	Matrix operator * (const Matrix &b) const
	{
		assert((int)a.size() == (int)b.size());
		int n = (int)a.size();
		Matrix res(n);
		for(int k=0; k<n; ++k)
			for(int i=0; i<n; ++i)
				for(int j=0; j<n; ++j)
					res[i][j] += a[i][k] * b[k][j];
		return res;
	}
	vector<ldb> operator * (const vector<ldb> &b) const
	{
		assert((int)a.size() == (int)b.size());
		int n = (int)a.size();
		vector<ldb> res(n);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				res[i] += a[i][j] * b[j];
		return res;
	}
};

Matrix inv(Matrix _a)
{
	int n = (int)_a.size();
	static ldb a[MAXN][MAXN * 2];
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
			a[i][j] = _a[i][j];
		for(int j=n; j<2*n; ++j)
			a[i][j] = 0;
		a[i][n+i] = 1;
	}
	for(int i=0; i<n; ++i)
	{
		int need = -1;
		for(int j=i; j<n; ++j)
			if(sgn(a[j][i])){ need = j; break;}
		assert(need != -1);
		if(need != i)
			for(int j=i; j<2*n; ++j)
				swap(a[i][j], a[need][j]);
		
		ldb mul = 1 / a[i][i];
		for(int j=i; j<2*n; ++j)
			a[i][j] *= mul;
		for(int ii=0; ii<n; ++ii) if(ii != i && sgn(a[ii][i]))
		{
			mul = -a[ii][i];
			for(int j=i; j<2*n; ++j)
				a[ii][j] += a[i][j] * mul;
		}
	}
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			_a[i][j] = a[i][n+j];
	return _a;
}

Matrix pw(Matrix a,int b)
{
	Matrix res(a.size());
	res.to_unit();
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a; b>>=1;
	}
	return res;
}

vector<int> g[MAXN];
int type[MAXN];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&type[i]);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	vector<int> vec;
	for(int i=1; i<=n; ++i) if(type[i] == 1)
		vec.push_back(i);
	int cnt = (int)vec.size();
	
	Matrix f(n);
	for(int i=1; i<=n; ++i)
	{
		f[i-1][i-1] = (int)g[i].size();
		if(type[i] == 1) continue;
		for(int j: g[i]) --f[i-1][j-1];
	}
	auto save = f;
	f = inv(f);
	
	auto getprob = [&] (int beg)
	{
		vector<ldb> tmp(n);
		tmp[beg-1] = 1;
		tmp = f * tmp;
		
		vector<ldb> res(cnt);
		for(int i=0; i<cnt; ++i)
			for(int j: g[vec[i]])
				res[i] += tmp[j-1];
		return res;
	};
	
	Matrix a(cnt);
	for(int i=0; i<cnt; ++i)
	{
		auto cur = getprob(vec[i]);
		for(int j=0; j<cnt; ++j) a[j][i] = cur[j];
	}
	
	auto ans = pw(a, d-2) * getprob(1);
	printf("%.20lf",(double)ans[cnt-1]);
	return 0;
}