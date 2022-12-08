#include <cstdio>
#include <cstring>
#include <functional>
#include <set>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MOD = 998244353;

struct mint
{
	public:
		int v;
		mint(int _v=0):v(_v){}

		explicit operator int() const {return v;}

		mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
		mint& operator *= (const mint& o) {return v=(ll)v*o.v%MOD, *this;}

		friend mint operator + (mint a, const mint& b) {return a+=b;}
		friend mint operator - (mint a, const mint& b) {return a-=b;}
		friend mint operator * (mint a, const mint& b) {return a*=b;}
};

const int MN = 3e5+10;
const int MM = 22;

int N, M, l[MN], r[MN], a[MN], b[MN], p[MN], min, max;
mint v[MN][MM*2], fact[2][MN], inv[MN], f;
std::set<int> ctr;

mint choose(int n, int k)
{
	if(k < 0 || n < k) return mint(0);
	return fact[0][n]*fact[1][k]*fact[1][n-k];
}

int main()
{
	inv[0]=0, inv[1]=1;
	fact[0][0]=fact[1][0]=fact[0][1]=fact[1][1]=1;
	for(int i=2;i<MN;++i)
	{
		inv[i]=inv[MOD%i]*mint(MOD-MOD/i);
		fact[0][i]=fact[0][i-1]*mint(i);
		fact[1][i]=fact[1][i-1]*inv[i];
	}
	scanf("%d%d", &N, &M);
	for(int i=0;i<N;++i) scanf("%d%d", l+i, r+i), --l[i], ++p[l[i]], --p[r[i]];
	for(int i=0;i<M;++i) scanf("%d%d", a+i, b+i), --a[i], --b[i];
	for(int i=0,c=0;i<N;++i)
	{
		c+=p[i];
		memcpy(v[i+1], v[i], sizeof*v);
		if(i+1<=c)
			for(int j=0;j<MM*2 && j<=i+1;++j)
				v[i+1][j]+=choose(c-j, i+1-j);
	}
	for(int i=0;i<1<<M;++i)
	{
		min=0, max=N;
		auto add=[&](int x)
		{
			ckmax(min, l[x]);
			ckmin(max, r[x]);
			ctr.insert(x);
		};
		int w=1;
		for(int j=0;j<M;++j)
			if(i>>j&1)
			{
				add(a[j]);
				add(b[j]);
				w*=-1;
			}
		int cnt=ctr.size();
		//printf("%d %d %d\n", cnt, min, max);
		if(max>min)
		{
			if(w>0)
				f += v[max][cnt]-v[min][cnt];
			else
				f -= v[max][cnt]-v[min][cnt];
		}
		ctr.clear();
	}
	printf("%d\n", f);
	return 0;
}