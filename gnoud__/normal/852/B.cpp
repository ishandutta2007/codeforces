#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N=1000050,M=100;
const ll mod=1e9+7;
int n,l,m;
int L[N],mid[N],R[N];
struct Matrix {ll m[M][M];} a,b;
Matrix operator *(Matrix a,Matrix b)
{
	Matrix c;
	forinc(i,0,M-1) forinc(j,0,M-1)
	{
	    c.m[i][j]=0;
        forinc(k,0,M-1)
        c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j]%mod)%mod;
	}
	return c;
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9') {x=x*10+c-'0';c=getchar();}
}
main()
{
    //freopen("852B.inp","r",stdin);
    //freopen("852B.out","w",stdout);
	read(n);read(l);read(m);l-=2;
	forinc(i,1,n) read(L[i]);
	forinc(i,1,n) read(mid[i]);
	forinc(i,1,n) read(R[i]);
	forinc(i,0,m-1) forinc(j,1,n)
    b.m[(i-mid[j]+m)%m][i]++;
	forinc(i,1,n) a.m[0][L[i]%m]++;
	while(l)
    {
		if(l&1) a=a*b;
		b=b*b; l>>=1;
	}
	ll sum=0;
	forinc(i,1,n)
	{
		sum+=ll(a.m[0][(m*2-mid[i]-R[i])%m]);
		sum%=mod;
	}
	cout<<sum;
}