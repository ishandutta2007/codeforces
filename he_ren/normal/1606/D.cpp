#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int MAXM = 5e5 + 5;
const int inf = 0x3f3f3f3f;

int n;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

char res[MAXN];
inline bool get_res(void)
{
	static int lef[MAXN], rig[MAXN];
	for(int i=1; i<=n; ++i) lef[i] = rig[i] = i;
	sort(lef+1,lef+n+1, [](int x,int y){ return b[x] > b[y];});
	sort(rig+1,rig+n+1, [](int x,int y){ return c[x] < c[y];});
	
	static bool is[MAXN];
	memset(is, 0, n+1);
	
	int mna = a[lef[1]], mxd = d[lef[1]];
	int p = 0, q = 0;
	while(1)
	{
		bool ok = 0;
		auto insert = [&] (int x)
		{
			if(!is[x])
			{
				is[x] = 1; ok = 1;
				mna = min(mna, a[x]);
				mxd = max(mxd, d[x]);
			}
		};
		
		while(p<n && b[lef[p+1]] >= mna) insert(lef[++p]);
		while(q<n && c[rig[q+1]] <= mxd) insert(rig[++q]);
		if(!ok) break;
	}
	
	if(p == n || q == n) return 0;
	for(int i=1; i<=n; ++i) res[i] = is[i]? 'R': 'B';
	return 1;
}

vector<int> mat[MAXN];

void solve(void)
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		mat[i].resize(m+2);
		for(int j=1; j<=m; ++j) scanf("%d",&mat[i][j]);
	}
	
	static vector<int> sufmn[MAXN], sufmx[MAXN];
	for(int i=1; i<=n; ++i)
	{
		sufmn[i].resize(m+2); sufmx[i].resize(m+2);
		sufmn[i][m+1] = inf; sufmx[i][m+1] = -inf;
		for(int j=m; j>=1; --j)
		{
			sufmn[i][j] = min(sufmn[i][j+1], mat[i][j]);
			sufmx[i][j] = max(sufmx[i][j+1], mat[i][j]);
		}
	}
	
	memset(a, 0x3f, (n+1)<<2);
	memset(b, 0xc0, (n+1)<<2);
	for(int k=1; k<m; ++k)
	{
		for(int i=1; i<=n; ++i)
		{
			a[i] = min(a[i], mat[i][k]);
			b[i] = max(b[i], mat[i][k]);
			c[i] = sufmn[i][k+1];
			d[i] = sufmx[i][k+1];
		}
		
		if(get_res())
		{
			res[n+1] = 0;
			printf("YES\n%s %d\n",res+1,k);
			return;
		}
	}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}