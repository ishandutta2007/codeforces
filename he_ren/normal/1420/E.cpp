#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 80 + 5;
const int MAXT = MAXN * MAXN;

inline int Abs(int x){ return x<0? -x: x;}
inline int squ(int x){ return x * x;}
inline int calc(int x){ return x * (x-1) / 2;}

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	vector<int> p;
	p.push_back(0);
	for(int i=1; i<=n; ++i)
		if(a[i]) p.push_back(i);
	int m = (int)p.size() - 1;
	
	int T = min(n * (n-1) / 2, 800);
	
	static int f[MAXN][MAXN][MAXN * MAXN];
	memset(f,0x3f,sizeof(f));
	
	for(int k=0; k<=T; ++k)
		f[0][0][k] = 0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m && j<=i; ++j)
		{
			int need = Abs(i - p[j]);
			for(int k=need; k<=T; ++k)
			{
				int &res = f[i][j][k];
				for(int l=j-1; l<i; ++l)
					res = min(res, f[l][j-1][k - need] + calc(i-l-1));
			}
		}
	}
	
	static int g[MAXN * MAXN];
	memset(g,0x3f,sizeof(g));
	
	for(int k=0; k<=T; ++k)
		for(int i=m; i<=n; ++i)
			g[k] = min(g[k], f[i][m][k] + calc(n-i));
	
	int tot = n * (n-1) / 2, all = calc(n-m);
	for(int k=0; k<=tot; ++k)
	{
		int res = (k<=T)? g[k]: g[T];
		printf("%d ",all - res);
	}
	return 0;
}