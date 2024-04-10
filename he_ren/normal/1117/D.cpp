#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXM = 1e2 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

ll n;
int m;

struct Matrix
{
	int g[MAXM][MAXM];
	Matrix(void){ memset(g,0,sizeof(g));}
	
	inline void clear(void){ memset(g,0,sizeof(g));}
	inline void set(void)
	{
		memset(g,0,sizeof(g));
		for(int i=1; i<=m; ++i) g[i][i]=1;
	}
	
	inline friend Matrix operator * (const Matrix &a,const Matrix &b)
	{
		Matrix c;
		for(int k=1; k<=m; ++k)
			for(int i=1; i<=m; ++i)
				for(int j=1; j<=m; ++j)
					add_mod(c.g[i][j], (ll)a.g[i][k]*b.g[k][j] %mod);
		return c;
	}
};

inline void pw(Matrix &res,Matrix a,ll b)
{
	res.set();
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
}

int main(void)
{
	scanf("%lld%d",&n,&m);
	
	Matrix ans,a;
	a.clear();
	a.g[1][1]=a.g[1][m]=1;
	for(int i=1; i<m; ++i)
		a.g[i+1][i]=1;
	pw(ans,a,n);
	
	printf("%d",ans.g[1][1]);
	return 0;
}