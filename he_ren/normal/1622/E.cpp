#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 10 + 5;
const int MAXM = 1e4 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int n,m;
int a[MAXN];
char s[MAXN][MAXM];

int p[MAXM];
inline ll get_res(int mask)
{
	ll has = 0;
	static int coef[MAXM];
	memset(coef, 0, (m+1)<<2);
	for(int i=1; i<=n; ++i)
	{
		int t = bdig(mask, i-1)? 1: -1;
		has += -t * a[i];
		for(int j=1; j<=m; ++j)
			if(s[i][j] == '1') coef[j] += t;
	}
	
	static int id[MAXM];
	for(int i=1; i<=m; ++i) id[i] = i;
	sort(id+1, id+m+1, [](int x,int y){
		return coef[x] < coef[y];
	});
	
	for(int i=1; i<=m; ++i) p[id[i]] = i;
	
	for(int i=1; i<=m; ++i)
		has += coef[i] * p[i];
	return has;
}

void solve(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	int all = (1<<n) - 1;
	
	ll ans = -linf;
	int ansmask = -1;
	for(int mask=0; mask<=all; ++mask)
	{
		ll cur = get_res(mask);
		if(cur > ans) ans = cur, ansmask = mask;
	}
	
	get_res(ansmask);
	for(int i=1; i<=m; ++i) printf("%d ",p[i]);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}