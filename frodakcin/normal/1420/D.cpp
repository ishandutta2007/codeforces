#include <cstdio>
#include <vector>
#include <algorithm>

const int MOD = 998244353;
using ll = long long;

struct mint
{
	public:
		int v;
		mint(int _v=0): v(_v) {}

		operator int() const {return v;}

		mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
		mint& operator *= (const mint& o) {return v=(ll)v*o.v%MOD, *this;}

		friend mint operator + (mint a, const mint& b) {return a+=b;}
		friend mint operator - (mint a, const mint& b) {return a-=b;}
		friend mint operator * (mint a, const mint& b) {return a*=b;}
};

const int MN = 3e5+10;

int N, K;
mint fact[2][MN], inv[MN], f;
std::vector<int> evt;

void pcp()
{
	fact[0][0]=fact[1][0]=mint(1);
	inv[0]=mint(0), inv[1]=mint(1);
	for(int i=1;i<MN;++i)
	{
		fact[0][i]=fact[0][i-1]*mint(i);
		if(i>1) inv[i]=inv[MOD%i]*mint(MOD-MOD/i);
		fact[1][i]=fact[1][i-1]*inv[i];
	}
}

mint choose(int n, int k)
{
	if(k < 0 || n < k) return mint(0);
	return fact[0][n]*fact[1][k]*fact[1][n-k];
}

int main()
{
	pcp();
	scanf("%d%d", &N, &K);
	for(int i=0;i<N;++i)
	{
		int l,r;
		scanf("%d%d", &l, &r);
		evt.push_back(l*2);
		evt.push_back(r*2+1);
	}
	std::sort(evt.begin(), evt.end());
	for(int i=0,ctr=0;i<evt.size();++i)
		if(evt[i]&1)
			--ctr;
		else
			f += choose(ctr++, K-1);
	printf("%d\n", f);
	return 0;
}