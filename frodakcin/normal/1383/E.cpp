#include <cstdio>

using ll = long long;

const int MN = 1e6+10;
const int MOD = 1e9+7;

struct mint
{
	public:
		int v;
		mint(int v=0) : v(v){}
		
		mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
		mint& operator *= (const mint& o) {v=(int)((ll)v*o.v%MOD); return *this;}

		friend mint operator + (mint a, const mint& b){return a+=b;}
		friend mint operator - (mint a, const mint& b){return a-=b;}
		friend mint operator * (mint a, const mint& b){return a*=b;}
		
		explicit operator int() const {return v;}
};

int N, a[MN], M, q[MN], Q;
char s[MN];
mint mult(1), d[MN], _p[MN], *p=_p+1;

int main()
{
	scanf(" %s", s);
	int x=-1;
	for(;s[N];++N)
		if(s[N]=='1')
		{
			if(!~x)
				mult*=mint(N+1);
			else
				a[M++]=N-x;
			x=N;
		}
	if(!~x) return printf("%d\n", N), 0;
	mult*=mint(N-x);
	d[0]=1, p[0]=1;
	q[Q++]=-1;
	for(int i=0,v;i<M;++i)
	{
		d[i+1]+=d[i]*mint(a[i]);
		for(;Q>1&&a[q[Q-1]]<=a[i];--Q)
		{
			d[i+1]+=mint(a[i]-a[q[Q-1]])*(p[q[Q-1]]-p[q[Q-2]]);
		}
		q[Q++]=i;
		p[i+1]=p[i]+d[i+1];
	}
	printf("%d\n", mult*p[M]);
	return 0;
}