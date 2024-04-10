#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 5 + 5;
const int ALL = (1<<5) + 5;
const int MAXD = MAXN * ALL;
const ll linf = 0x3f3f3f3f3f3f3f3f;

mt19937 rnd((unsigned long long)new char ^ time(0));

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int n,m,all;
int a[MAXN][MAXM], wei[MAXN];
int val[MAXN][ALL];

int cnt[MAXD];
void update(int i,int k)
{
	for(int mask=0; mask<=all; ++mask)
		cnt[val[i][mask]] += k;
}
int query(int i)
{
	int res = 0;
	for(int mask=0; mask<=all; ++mask)
		res += __builtin_parity(mask)? -cnt[val[i][mask]]: cnt[val[i][mask]];
	return res;
}

int mxj[MAXN];
void divid(int l,int r,int id[],int len)
{
	if(!len) return;
	if(l == r)
	{
		for(int i=1; i<=len; ++i)
			mxj[id[i]] = l;
		return;
	}
	
	int mid = (l+r)>>1;
	for(int i=mid+1; i<=r; ++i)
		update(i, 1);
	int lef = 0;
	for(int i=1; i<=len; ++i)
		if(!query(id[i]))
			swap(id[i], id[++lef]);
	
	divid(l, mid, id, lef);
	for(int i=mid+1; i<=r; ++i)
		update(i, -1);
	divid(mid+1, r, id+lef, len-lef);
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j) scanf("%d",&a[i][j]);
		scanf("%d",&wei[i]);
	}
	
	{
		static int ord[MAXN];
		iota(ord+1, ord+n+1, 1);
		sort(ord+1, ord+n+1, [&] (int i,int j){
			return wei[i] > wei[j];
		});
		
		static int _a[MAXN][MAXM], _wei[MAXN];
		for(int i=1; i<=n; ++i)
		{
			_wei[i] = wei[ord[i]];
			memcpy(_a[i], a[ord[i]], sizeof(_a[i]));
		}
		memcpy(a, _a, sizeof(_a));
		memcpy(wei, _wei, sizeof(_wei));
	}
	
	all = (1<<m) - 1;
	
	static ull tval[MAXN][ALL];
	{
		static int dsc[MAXN * MAXM], dcnt = 0;
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
				dsc[++dcnt] = a[i][j];
		sort(dsc+1,dsc+dcnt+1);
		dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
				a[i][j] = lower_bound(dsc+1,dsc+dcnt+1,a[i][j]) - dsc;
		
		static ull h[MAXN * MAXM];
		for(int i=1; i<=dcnt; ++i)
			h[i] = ((ull)rnd()) << 32 | rnd();
		for(int i=1; i<=n; ++i)
			for(int mask=0; mask<=all; ++mask)
				for(int j=1; j<=m; ++j) if(bdig(mask, j-1))
					tval[i][mask] ^= h[a[i][j]];
	}
	{
		static ull dsc[MAXD];
		int dcnt = 0;
		for(int i=1; i<=n; ++i)
			for(int mask=0; mask<=all; ++mask)
				dsc[++dcnt] = tval[i][mask];
		sort(dsc+1,dsc+dcnt+1);
		dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
		for(int i=1; i<=n; ++i)
			for(int mask=0; mask<=all; ++mask)
				val[i][mask] = lower_bound(dsc+1,dsc+dcnt+1,tval[i][mask]) - dsc;
	}
	
//	for(int i=1; i<=n; ++i)
//		for(int mask=0; mask<=all; ++mask)
//			printf("val[%d][%d] = %d\n",i,mask,val[i][mask]);
	
	static int id[MAXN];
	iota(id+1, id+n+1, 1);
	divid(0, n, id, n);
	
	ll ans = linf;
	for(int i=1; i<=n; ++i)
		if(mxj[i]) ans = min(ans, (ll)wei[i] + wei[mxj[i]]);
	if(ans < linf)
		printf("%lld",ans);
	else
		printf("-1");
	return 0;
}