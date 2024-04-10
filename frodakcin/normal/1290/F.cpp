#include <cstdio>

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MOD = 998244353;
 
//copied from benq
struct mint
{
public:
	int val;
	mint(int _val = 0) : val(_val)
	{
		val = (-MOD <= val && val < MOD) ? val : val%MOD;
		if(val < 0) val += MOD;
	}
	explicit operator int () const {return val;}

	mint operator -() const {return mint(-val);}
	mint& operator += (mint m) {if((val += m.val) >= MOD) val -= MOD; return *this;}
	mint& operator -= (mint m) {if((val -= m.val) < 0) val += MOD; return *this;}
	mint& operator *= (mint m) {val = ti(tl(val)*m.val%MOD); return *this;}

	friend mint pow(mint a, int p)
	{
		mint r(1);
		for(;p;p>>=1, a*=a) if(p&1) r*=a;
		return r;
	}

	friend mint operator + (mint a, mint b) {return a += b;}
	friend mint operator - (mint a, mint b) {return a -= b;}
	friend mint operator * (mint a, mint b) {return a *= b;}
};

const int MN = 5, MX = 20, LG = 30;
int N, M;
int x[MN], y[MN];
mint dp[2][MX][MX][MX][MX][2][2];
/*
conditions:
	+x = -x
	+y = -y
	+x <= M
	+y <= M
	*/

int main(void)
{
	scanf("%d%d", &N, &M);
	for(int i = 0;i < N;++i)
		scanf("%d%d", x+i, y+i);
	dp[0][0][0][0][0][0][0] = mint(1);
	for(int i = M;i;i>>=1)
	{
		bool m = i&1;
		for(int px = 0;px < MX;++px)
			for(int nx = 0;nx < MX;++nx)
				for(int py = 0;py < MX;++py)
					for(int ny = 0;ny < MX;++ny)
						for(int xm = 0;xm < 2;++xm)
							for(int ym = 0;ym < 2;++ym)
								if(ti(dp[0][px][nx][py][ny][xm][ym]))
									for(int mask = 0;mask < 1<<N;++mask)
									{
										int px1 = px, nx1 = nx, py1 = py, ny1 = ny;
										for(int k = 0;k < mask;++k)
											if(mask>>k&1)
											{
												if(x[k]>0) px1 += x[k];
												else nx1 -= x[k];
												if(y[k]>0) py1 += y[k];
												else ny1 -= y[k];
											}
										if(1&(nx1^px1) || 1&(ny1^py1)) continue;
										bool vx1 = nx1&1, vy1 = ny1&1;
										dp[1][px1>>1][nx1>>1][py1>>1][ny1>>1][m==vx1?xm:vx1][m==vy1?ym:vy1] += dp[0][px][nx][py][ny][xm][ym];
									}
		for(int px = 0;px < MX;++px)
			for(int nx = 0;nx < MX;++nx)
				for(int py = 0;py < MX;++py)
					for(int ny = 0;ny < MX;++ny)
						for(int xm = 0;xm < 2;++xm)
							for(int ym = 0;ym < 2;++ym)
								dp[0][px][nx][py][ny][xm][ym] = dp[1][px][nx][py][ny][xm][ym], dp[1][px][nx][py][ny][xm][ym] = mint(0);
	}
	// subtract off zero vector
	printf("%d\n", ti(dp[0][0][0][0][0][0][0]-mint(1)));
	return 0;
}