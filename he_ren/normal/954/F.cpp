#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 5;
const int MAXP = MAXN*4;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

struct Seg
{
	int x;
	ll l,r;
}a[MAXN];

ll dsc[MAXP];
int dcnt=0;

int dif[4][MAXP],f[4][MAXP];

struct Matrix
{
	int g[4][4];
	Matrix(){ memset(g,1,sizeof(g));}
	inline void set(void)
	{
		for(int i=1; i<=3; ++i)
			for(int j=1; j<=3; ++j) g[i][j]=1;
	}
	inline void reset(void)
	{
		memset(g,0,sizeof(g));
		for(int i=1; i<=3; ++i) g[i][i]=1;
	}
	
	void operator *= (const Matrix b)
	{
		const Matrix c=*this;
		memset(g,0,sizeof(g));
		
		for(int k=1; k<=3; ++k)
			for(int i=1; i<=3; ++i)
				for(int j=1; j<=3; ++j)
					add_mod(g[i][j], (ll)b.g[i][k] * c.g[k][j] %mod);
	}
}res,g;

void pw(Matrix &a,ll b)
{
	res.reset();
	while(b)
	{
		if(b&1ll) res*=a;
		a*=a;
		b>>=1ll;
	}
}

int main(void)
{
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1; i<=n; ++i)
		cin>>a[i].x>>a[i].l>>a[i].r;
	
	for(int i=1; i<=n; ++i)
	{
		dsc[++dcnt] = a[i].l; dsc[++dcnt] = a[i].r;
		dsc[++dcnt] = a[i].l-1; dsc[++dcnt] = a[i].r+1;
	}
	dsc[++dcnt]=1; dsc[++dcnt]=m;
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1)-dsc-1;
	for(int i=1; i<=n; ++i)
		a[i].l = lower_bound(dsc+1,dsc+dcnt+1, a[i].l) - dsc,
		a[i].r = lower_bound(dsc+1,dsc+dcnt+1, a[i].r) - dsc;
	
	for(int i=1; i<=n; ++i)
		++dif[a[i].x][a[i].l],
		--dif[a[i].x][a[i].r+1];
	
	for(int i=1; i<=3; ++i)
		for(int j=1; j<=dcnt; ++j)
			dif[i][j] += dif[i][j-1];
	
	f[2][1]=1;
	for(int j=2; j<=dcnt; ++j)
	{
		g.set();
		g.g[1][3] = g.g[3][1] = 0;
		for(int i=1; i<=3; ++i) if(dif[i][j])
			for(int k=1; k<=3; ++k)
				g.g[i][k] = 0;
		for(int i=1; i<=3; ++i) if(dif[i][j-1])
			for(int k=1; k<=3; ++k)
				g.g[k][i] = 0;
		
		pw(g,dsc[j]-dsc[j-1]);
		
		for(int i=1; i<=3; ++i)
			for(int k=1; k<=3; ++k)
				add_mod(f[i][j], (ll)res.g[i][k] * f[k][j-1] %mod);
	}
	
	/*
	for(int i=1; i<=3; ++i, putchar('\n'))
		for(int j=1; j<=dcnt; ++j)
			printf("%2d ",f[i][j]);
	*/
	
	printf("%d",f[2][dcnt]);
	return 0;
}