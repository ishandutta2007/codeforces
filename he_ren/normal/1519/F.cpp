#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 6 + 5;
const int MAXM = 6 + 5;
const int base = 5;
const int ALL = 1.6e4 + 5;
const int inf = 0x3f3f3f3f;

int pwb[MAXM];

int n,m;
int a[MAXN], b[MAXM], c[MAXN][MAXM];
int f[MAXN][ALL];

inline int encode(int t[])
{
	int res = 0;
	for(int i=m; i>=1; --i)
		res = res * base + t[i];
	return res;
}

inline int get_dig(int mask,int k)
{
	return mask / pwb[k - 1] % base;
}

inline int reduce(int mask,int k,int x)
{
	return mask - x * pwb[k - 1];
}

inline void dfs_f(int dep,int mask,int curc,int rem,int lvl)
{
	if(dep > m)
	{
		if(!rem) f[lvl][mask] = min(f[lvl][mask], curc);
		return;
	}
	
	dfs_f(dep+1, mask, curc, rem, lvl);
	
	curc += c[lvl][dep];
	int lim = min(rem, get_dig(mask, dep));
	
	for(int i=1; i<=lim; ++i)
		dfs_f(dep+1, reduce(mask, dep, i), curc, rem - i, lvl);
}

int main(void)
{
	pwb[0] = 1;
	for(int i=1; i<MAXM; ++i) pwb[i] = pwb[i-1] * base;
	
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) scanf("%d",&c[i][j]);
	
	int tot = 0;
	for(int i=1; i<=n; ++i) tot += a[i];
	for(int i=1; i<=m; ++i) tot -= b[i];
	if(tot > 0) return printf("-1"), 0;
	
	int all = pwb[m] - 1;
	memset(f,0x3f,sizeof(f));
	f[0][encode(b)] = 0;
	for(int i=1; i<=n; ++i)
	{
		for(int mask=0; mask<=all; ++mask)
			if(f[i-1][mask] < inf) dfs_f(1, mask, f[i-1][mask], a[i], i);
	}
	
	int res = *min_element(f[n], f[n]+all+1);
	if(res == inf) printf("-1");
	else printf("%d",res);
	return 0;
}