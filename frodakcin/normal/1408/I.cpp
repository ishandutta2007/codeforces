#include <cstdio>
#include <vector>
#include <algorithm>

using ll = long long;

const int MOD = 998244353;
const int MK = 17;
const int MV = 1 << 16;

struct mint
{
	public:
		int v;
		mint(int _v=0):v(_v){}
		explicit operator int() const {return v;}

		mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
		mint& operator *= (const mint& o) {v=(ll)v*o.v%MOD; return *this;}

		friend mint operator + (mint a, const mint& b) {return a+=b;}
		friend mint operator - (mint a, const mint& b) {return a-=b;}
		friend mint operator * (mint a, const mint& b) {return a*=b;}

		friend mint pow(mint b, ll p)
		{
			mint f(1);
			for(;p;p>>=1, b*=b)
				if(p&1)
					f*=b;
			return f;
		}
};

int N, K, C, f;
mint dp[MK][MV], ch[MK][MK];
std::vector<int> evt[MK];

void gen_ch()
{
	for(int i=0;i<MK;++i)
	{
		ch[i][i]=ch[i][0]=mint(1);
		for(int j=1;j<i;++j)
			ch[i][j] = ch[i-1][j]+ch[i-1][j-1];
	}
}

int main()
{
	gen_ch();
	scanf("%d%d%d", &N, &K, &C);
	for(int i=0;i<N;++i)
	{
		int v; scanf("%d", &v);
		int b=0;
		for(;;++b)	//b must be leq C
			if((v&((1<<b)-1)) >= K)
				break;
		int t=(1<<b)-1;
		evt[b-1].push_back(v&t);
		f ^= v;
	}
	dp[0][0]=mint(1);
	for(int i=0;i<C;++i)
	{
		std::sort(evt[i].begin(), evt[i].end());
		for(int v:evt[i])
			for(int j=K-1;j>=0;--j)
				for(int x=0;x<1<<i;++x)
					if((int)dp[j][x])
						for(int k=1;j+k<=K;++k)
							dp[j+k][x^(v^v-k)>>1]+=dp[j][x]*ch[j+k][k];
	}
	mint c=pow(mint(N), (ll)K*(MOD-2));
	bool lb = (f^K)&1;
	for(int i=0;i<1<<C;++i)
		printf("%d%c", (i&1^!lb ? dp[K][(i^f)>>1]*c : 0), " \n"[i+1==(1<<C)]);
	return 0;
}