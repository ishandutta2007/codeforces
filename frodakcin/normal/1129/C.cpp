#include <cstdio>
#include <cstring>

using ll = long long;

const int MOD = 1e9+7;

struct mint
{
	int v;
	mint(): v(0) {}
	template<typename T> mint(T _v)
	{
		if(_v < -MOD || MOD <= _v) _v %= MOD;
		v = (int)_v;
		if(v<0) v+=MOD;
	}

	explicit operator int() {return v;}

	mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
	mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
	mint& operator *= (const mint& o) {v=(ll)o.v*v%MOD; return *this;}

	friend mint operator + (mint a, const mint& b) {return a+=b;}
	friend mint operator - (mint a, const mint& b) {return a-=b;}
	friend mint operator * (mint a, const mint& b) {return a*=b;}
};

const int MM = 3e3+10;

int M;
bool s[MM], bad[][4] = {{0,0,1,1},{0,1,0,1},{1,1,1,0},{1,1,1,1}};
mint dp[MM][MM]; // dp[l][r], inc/exc

namespace A
{
	int c[MM*2][2], l[MM*2], d[MM*2], X;
	void init()
	{
		memset(c, -1, sizeof c);
		l[0]=-1;
		d[0]=0;
		X=0;
	}
	int append(int p, char x)
	{
		int n=++X;
		d[n]=d[p]+1;
		for(;p != -1 && c[p][x] == -1;p=l[p])
			c[p][x]=n;
		if(p == -1)
			l[n]=0;
		else
		{
			int q=c[p][x];
			if(d[q] == d[p]+1)
				l[n]=q;
			else
			{
				l[n] = ++X;
				memcpy(c[X], c[q], sizeof*c);
				l[X]=l[q];

				d[l[n]]=d[p]+1;
				l[q]=l[n];
				for(;p != -1 && c[p][x] == q;p=l[p])
					c[p][x]=l[n];
			}
		}
		return n;
	}
}

int main()
{
	A::init();
	scanf("%d", &M);

	dp[0][0]=mint(1);
	mint ans;
	for(int i=0, n=0;i<M;++i)
	{
		int _s; scanf(" %d", &_s); s[i]=_s;

		for(int j=0;j<=i;++j)
		{
			for(int k=0;k<=2 && i-k >= j;++k)
				dp[j][i+1] += dp[j][i-k];
			//check
			if(i-3 >= j)
			{
				bool ok=1;
				for(int x=0,y;ok && x<4;++x) // bad[x][..]
				{
					for(y=0;y<4;++y)
						if(bad[x][y] != s[i-3+y])
							break;
					if(y==4) ok=0;
				}
				if(ok)
					dp[j][i+1] += dp[j][i-3];
			}
		}
		n = A::append(n, s[i]);
		dp[i+1][i+1]=mint(1);
		for(int j=i-A::d[A::l[n]];j>=0;--j)
			ans += dp[j][i+1];
		//printf("%d -- ", A::d[A::l[n]]);
		printf("%d\n", ans);
	}
	//for(int i=0;i<M;++i) for(int j=i;j<=M;++j) printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
	return 0;
}