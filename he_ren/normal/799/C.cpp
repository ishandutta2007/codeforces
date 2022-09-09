#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int mx[MAXN];

int calc(int a[],int b[],int n,int has)
{
	mx[0] = 0;
	for(int i=1; i<=n; ++i)
		mx[i] = max(mx[i-1], a[i]);
	
	int res = 0;
	for(int i=1; i<=n; ++i)
		if(b[i] <= has)
		{
			int pos = upper_bound(b+1, b+i, has - b[i]) - b - 1;
			if(pos >= 1)
				res = max(res, mx[pos] + a[i]);
		}
	return res;
}

int tot, P, Q, a[MAXN], b[MAXN], id[MAXN];
char c[MAXN];

bool cmp(int x,int y)
{
	return b[x] < b[y];
}

int n, m, pa[MAXN], pb[MAXN], qa[MAXN], qb[MAXN];

int main(void)
{
	scanf("%d %d %d",&tot,&P,&Q);
	for(int i=1; i<=tot; ++i)
		scanf("%d %d %c",&a[i],&b[i],&c[i]);
	
	for(int i=1; i<=tot; ++i)
		id[i] = i;
	sort(id+1, id+tot+1, cmp);
	
	for(int i=1; i<=tot; ++i)
	{
		if(c[id[i]] == 'C')
		{
			++n;
			pa[n] = a[id[i]];
			pb[n] = b[id[i]];
		}
		else
		{
			++m;
			qa[m] = a[id[i]];
			qb[m] = b[id[i]];
		}
	}
	
	int ans = 0;
	ans = max(ans, calc(pa, pb, n, P));
	ans = max(ans, calc(qa, qb, m, Q));
	
	int mxp = -1, mxq = -1;
	for(int i=1; i<=n; ++i)
		if(pb[i] <= P) mxp = max(mxp, pa[i]);
	for(int i=1; i<=m; ++i)
		if(qb[i] <= Q) mxq = max(mxq, qa[i]);
	
	if(mxp != -1 && mxq != -1)
		ans = max(ans, mxp + mxq);
	
	printf("%d",ans);
	return 0;
}