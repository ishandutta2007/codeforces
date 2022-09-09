#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;
const int d = 3;
const int MAXD = d + 5;
const int lb = 31;
const int LB = lb + 5;
const int mod = 998244353;
const int maxs = (d + 1) * (d + 1) * (d + 1);

#define bit(x) (1ll<<(x))
#define lowbit(x) ((x)&-(x))

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

template<const int n>
struct Matrix
{
	int a[n+1][n+1];
	inline void clear(void){ memset(a,0,sizeof(a));}
	inline int* operator [] (const int x){ return a[x];}
	inline const int* operator [] (const int x) const { return a[x];}
	
	inline void operator += (const Matrix<n> &b)
	{
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				add_mod(a[i][j], b[i][j]);
	}
	inline void mul_right(const Matrix<n> &b)
	{
		static Matrix c; c.clear();
		for(int k=1; k<=n; ++k)
			for(int i=1; i<=n; ++i)
				for(int j=1; j<=n; ++j)
					c[i][j] = (c[i][j] + (ll)a[i][k] * b[k][j]) %mod;
		*this = c;
	}
	inline void mul_left(const Matrix<n> &b)
	{
		static Matrix<n> c; c.clear();
		for(int k=1; k<=n; ++k)
			for(int i=1; i<=n; ++i)
				for(int j=1; j<=n; ++j)
					add_mod(c[i][j], (ll)b[i][k] * a[k][j] %mod);
		*this = c;
	}
};

template<const int n>
struct Vector
{
	int a[n+1];
	inline void clear(void){ memset(a,0,sizeof(a));}
	inline int& operator [] (const int x){ return a[x];}
	inline int& operator [] (const int x) const { return a[x];}
	inline void operator *= (const Matrix<n> &b)
	{
		static Vector<n> c; c.clear();
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				c[i] = (c[i] + (ll)a[j] * b[i][j]) %mod;
		*this = c;
	}
};

int a[MAXN];
vector<pii> pos[MAXN];
int ok[MAXD][MAXD];

Matrix<maxs> from[MAXD], mat[LB];
inline int get_state(int sg1,int sg2,int sg3){ return (sg1 | (sg2<<2) | (sg3<<4)) + 1;}
inline int get_mex(int mask){ return (mask&1)? (mask&2)? (mask&4)? 3: 2: 1: 0;}

void pw_mat(Vector<maxs> &vec,int b)
{
	static Matrix<maxs> res;
	res.clear();
	for(int i=1; i<=maxs; ++i)
		res[i][i] = 1;
	
	for(int i=0; b>>i; ++i)
		if(b & bit(i)) vec *= mat[i];
}

int ways[MAXN][MAXD];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		pos[x].push_back(make_pair(y,c));
	}
	for(int i=1; i<=d; ++i)
		for(int j=1; j<=d; ++j)
			scanf("%d",&ok[i][j]);
	
	#define for_all_state(i) for(int i##1=0; i##1<=3; ++i##1) for(int i##2=0; i##2<=3; ++i##2) for(int i##3=0; i##3<=3; ++i##3)
	#define now_state(i) get_state(i##1, i##2, i##3)
	
	for(int i=1; i<=3; ++i)
		for_all_state(sg)
		{
			int mask = 0;
			if(ok[i][1]) mask |= (1<<sg1);
			if(ok[i][2]) mask |= (1<<sg2);
			if(ok[i][3]) mask |= (1<<sg3);
			
			++from[i][ get_state(get_mex(mask), sg1, sg2) ][ now_state(sg) ];
		}
	
	mat[0].clear();
	for(int i=1; i<=3; ++i)
		mat[0] += from[i];
	
	for(int i=1; i<=lb; ++i)
		mat[i] = mat[i-1],
		mat[i].mul_right(mat[i-1]);
	
	for(int i=1; i<=n; ++i)
	{
		sort(pos[i].begin(), pos[i].end());
		
		if(a[i] == 1)
		{
			ways[i][0] = pos[i].empty()? 3: 1;
			continue;
		}
		
		static Vector<maxs> vec;
		vec.clear();
		
		static int must[4];
		must[1] = must[2] = must[3] = 0;
		for(int j=0; j<(int)pos[i].size() && pos[i][j].first <= 3; ++j)
			must[pos[i][j].first] = pos[i][j].second;
		
		if(a[i] == 2)
		{
			for(int c1=1; c1<=3; ++c1) if(!must[1] || c1 == must[1])
			for(int c2=1; c2<=3; ++c2) if(!must[2] || c2 == must[2])
				++ways[i][ok[c2][1]];
			continue;
		}
			
		for(int c1=1; c1<=3; ++c1) if(!must[1] || c1 == must[1])
		for(int c2=1; c2<=3; ++c2) if(!must[2] || c2 == must[2])
		for(int c3=1; c3<=3; ++c3) if(!must[3] || c3 == must[3])
		{
			int sg1 = 0, sg2 = ok[c2][1], mask = 0;
			if(ok[c3][2]) mask |= (1<<sg1);
			if(ok[c3][1]) mask |= (1<<sg2);
			++vec[get_state(get_mex(mask), sg2, sg1)];
		}
		
		int cur = 3;
		for(int j=0; j<(int)pos[i].size(); ++j)
		{
			if(pos[i][j].first <= 3) continue;
			int x = pos[i][j].first, clr = pos[i][j].second;
			
			if(x - cur - 1) pw_mat(vec, x - cur - 1);
			vec *= from[clr];
			cur = x;
		}
		if(a[i] - cur) pw_mat(vec, a[i] - cur);
		
		for_all_state(sg)
			add_mod(ways[i][sg1], vec[now_state(sg)]);
	}
	
	static ll dp[MAXN][MAXD];
	
	dp[0][0] = 1;
	for(int i=1; i<=n; ++i)
		for(int j=0; j<=3; ++j)
			for(int k=0; k<=3; ++k)
				dp[i][j^k] = (dp[i][j^k] + dp[i-1][j] * ways[i][k]) %mod;
	
	printf("%lld",dp[n][0]);
	return 0;
}