#include <bits/stdc++.h>
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define int long long
using namespace std;
const int mod=1000000007,N=101;
struct Matrix{int l,r;int m[N][N];}a,b,oo;
Matrix operator*(Matrix a,Matrix b)
{
	Matrix c=oo; c.l=a.l; c.r=b.r;
	forinc(i,1,c.l) forinc(j,1,c.r)
	{
		c.m[i][j]=0;
		forinc(k,1,a.r) (c.m[i][j]+=a.m[i][k]*b.m[k][j])%=mod;
	}
	return c;
}
Matrix pw(Matrix a,int b)
{
	Matrix c=oo;
	c.l=a.l;c.r=a.r;
	forinc(i,1,c.l) c.m[i][i]=1;
	for(;b;b/=2,a=a*a) if(b%2) c=c*a;
	return c;
}
main()
{
    //freopen("OKABE.inp","r",stdin);
    //freopen("OKABE.out","w",stdout);
	int n,k; cin>>n>>k;
	a.l=1;a.r=1;a.m[1][1]=1;
	b.l=16;b.r=16;
	forinc(i,1,16) b.m[i][i]=b.m[i][i-1]=b.m[i][i+1]=1;
	forinc(i,1,n)
	{
		int l,r,p;
		cin>>l>>r>>p;++p;
		r=min(r,k);
		a.l=p;b.l=p;b.r=p;
		a=a*pw(b,r-l);
		if(r==k)break;
	}
	cout<<a.m[1][1];
}