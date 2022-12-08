#include <cstdio>
#include <cassert>

using ll = long long;

const int MOD = 998244353;

struct mint
{
	public:
		int v;
		mint(int _v=0): v(_v){}

		mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
		mint& operator *= (const mint& o) {v=(ll)v*o.v%MOD; return *this;}

		friend mint operator + (mint a, const mint& b) {return a+=b;}
		friend mint operator - (mint a, const mint& b) {return a-=b;}
		friend mint operator * (mint a, const mint& b) {return a*=b;}
};

const int MN = 2e5+10;
const int MM = 2e5+10;

mint inv[MN], F[2][MN], p2i[MN];

void pcp()
{
	inv[1]=mint(1);
	for(int i=2;i<MN;++i)
		inv[i]=mint(MOD-MOD/i)*inv[MOD%i];
	F[0][0]=F[1][0]=mint(1);
	for(int i=1;i<MN;++i)
		F[0][i]=F[0][i-1]*mint(i), F[1][i]=F[1][i-1]*inv[i];
	p2i[0]=mint(1);
	for(int i=1;i<MN;++i)
		p2i[i]=p2i[i-1]*inv[2];
}

mint choose(int n, int k) {assert(0 <= k && k <= n); return F[0][n]*F[1][k]*F[1][n-k];}

int N, M;
char s[MN];

int main()
{
	pcp();
	scanf("%d%d %s", &N, &M, s);

	int shift=0, qm=0;
	for(int i=0;i<N;++i)
		if(s[i]=='?')
			++qm;
		else
			shift += (s[i]=='b' ^ i&1)*2-1;

	mint ans(0);
	for(int i=0;i<=qm;++i)
	{
		int v=shift + i*2 - qm;
		if(!(v&3))
			ans += mint(abs(v)/4) * choose(qm, i);
	}

	printf("%d\n", ans*p2i[qm-1]);
	return 0;
}