#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define x0 x00000
#define x1 x11111
#define y0 y00000
#define y1 y11111
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int MAXM = 1e2 + 5;

int a[MAXN][MAXM];

struct Oper
{
	int x[4], y[4];
	Oper(void){}
	Oper(int x1,int y1,int x2,int y2,int x3,int y3)
	{
		x[1] = x1; y[1] = y1;
		x[2] = x2; y[2] = y2;
		x[3] = x3; y[3] = y3;
	}
	Oper(int xx,int yy)
	{
		int nx = (xx&1)? xx+1: xx-1, ny = (yy&1)? yy+1: yy-1;
		x[1] = xx; y[1] = yy;
		x[2] = xx; y[2] = ny;
		x[3] = nx; y[3] = yy;
	}
	
	inline void chg(void) const
	{
		for(int i=1; i<=3; ++i)
			a[x[i]][y[i]] ^= 1;
	}
	inline void print(void){ printf("%d %d %d %d %d %d\n",x[1],y[1],x[2],y[2],x[3],y[3]);}
};

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		static char s[MAXM];
		scanf("%s",s+1);
		for(int j=1; j<=m; ++j) a[i][j] = s[j] - '0';
	}
	
	vector<Oper> ans;
	if(n & 1)
	{
		for(int j=1; j<=m; ++j)
			if(a[n][j])
			{
				if(j > 1) ans.push_back(Oper(n,j, n-1,j, n-1,j-1));
				else ans.push_back(Oper(n,j, n-1,j, n-1,j+1));
				
				ans.back().chg();
			}
		--n;
	}
	
//	for(int i=1; i<=n+1; ++i, putchar('\n'))
//		for(int j=1; j<=m; ++j) printf("%d ",a[i][j]); printf("\n");
	
	if(m&1)
	{
		for(int i=1; i<=n; ++i)
			if(a[i][m])
			{
				if(i > 1) ans.push_back(Oper(i,m, i,m-1, i-1,m-1));
				else ans.push_back(Oper(i,m, i,m-1, i+1,m-1));
				
				ans.back().chg();
			}
		--m;
	}
	
//	for(int i=1; i<=n+1; ++i, putchar('\n'))
//		for(int j=1; j<=m+1; ++j) printf("%d ",a[i][j]); printf("\n");
	
	for(int i=1; i<=n; i+=2)
		for(int j=1; j<=m; j+=2)
		{
			int cnt = a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1];
			if(!cnt) continue;
			
			if(cnt == 4)
			{
				for(int x=0; x<=1; ++x)
					for(int y=0; y<=1; ++y)
						ans.push_back(Oper(i+x, j+y)), ans.back().chg();
				continue;
			}
			
			if(cnt == 2)
			{
				if((a[i][j] && a[i+1][j+1]) || (a[i+1][j] && a[i][j+1]))
				{
					for(int x=0; x<=1; ++x)
						for(int y=0; y<=1; ++y)
							if(a[i+x][j+y])
								ans.push_back(Oper(i+x, j+y));
				}
				else
				{
					for(int x=0; x<=1; ++x)
						for(int y=0; y<=1; ++y)
							if(!a[i+x][j+y])
								ans.push_back(Oper(i+x, j+y));
				}
				for(int k=1; k<=2; ++k)
					(ans.end() - k) -> chg();
				continue;
			}
			
			if(cnt == 3)
			{
				for(int x=0; x<=1; ++x)
					for(int y=0; y<=1; ++y)
						if(!a[i+!x][j+!y])
							ans.push_back(Oper(i+x, j+y));
				ans.back().chg(); 
				continue;
			}
			
			if(cnt == 1)
			{
				for(int x=0; x<=1; ++x)
					for(int y=0; y<=1; ++y)
						if(!a[i+!x][j+!y])
							ans.push_back(Oper(i+x, j+y));
				for(int k=1; k<=3; ++k)
					(ans.end() - k) -> chg();
				continue;
			}
		}
	
//	for(int i=1; i<=n; ++i, putchar('\n'))
//		for(int j=1; j<=m; ++j) printf("%d ",a[i][j]);
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		ans[i].print();
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}

/*
1
4 4
0110
0110
0110
0110
*/