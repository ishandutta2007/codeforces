#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int MAXA = 1e6 + 5;
const int MAXP = 8e4 + 5;

bool isnp[MAXA];
int pri[MAXA], mnp[MAXA], pcnt = 0;
void sieve(int n)
{
	isnp[0] = isnp[1] = 1;
	for(int i=2; i<=n; ++i)
	{
		if(!isnp[i]) pri[++pcnt] = i, mnp[i] = pcnt;
		for(int j=1; j<=pcnt && (ll)i*pri[j]<=n; ++j)
		{
			isnp[i*pri[j]] = 1;
			mnp[i*pri[j]] = j;
			if(!(i%pri[j])) break;
		}
	}
}

struct Segment_Tree
{
	int mn[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	void update(int u,int l,int r,int q,int k)
	{
		if(l == r){ mn[u] = k; return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
		mn[u] = min(mn[ls(u)], mn[rs(u)]);
	}
}tmn;

int a[MAXN];
char s[MAXN];
vector<pii> pts[MAXP];

int main(void)
{
	sieve(MAXA-1);
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	scanf("%s",s+1);
	
	for(int i=1; i<=n; ++i)
	{
		int lst = -1, cnt = 0;
		int x = a[i];
		while(x > 1)
		{
			int cur = mnp[x]; x /= pri[cur];
			if(cur != lst)
			{
				if(cnt) pts[lst].emplace_back(i, cnt);
				lst = cur; cnt = 0;
			}
			++cnt;
		}
		if(cnt) pts[lst].emplace_back(i, cnt);
	}
	
	static vector<pii> tag[MAXN];
	for(int curp=1; curp<=pcnt; ++curp) if(pts[curp].size())
	{
		vector<pii> &pt = pts[curp];
//		printf("curp = %d\n",curp);
//		for(pii x: pt) printf("pt: (%d, %d)\n",x.first,x.second);
		
		int m = (int)pt.size();
		vector<int> val(m);
		for(int i=0; i<m; ++i)
		{
			int pos = pt[i].first;
			if(s[pos] == '*') val[i] = pt[i].second;
			else val[i] = -pt[i].second;
		}
//		printf("val = ");
//		for(int x: val) printf("%d ",x);
//		printf("\n");
		
		pt.emplace_back(n+1, 0);
		val.emplace_back(0);
		
		vector<int> vec(1, m);
		for(int i=m-1; i>=0; --i)
		{
			val[i] += val[i+1];
			while(vec.size() && val[vec.back()] <= val[i]) vec.pop_back();
			
			int r = vec.size()? pt[vec.back() - 1].first - 1: n;
			tag[pt[i].first].emplace_back(curp, r);
			vec.push_back(i);
		}
	}
	
	ll ans = 0;
	for(int i=1; i<=pcnt; ++i) tmn.update(1,1,pcnt,i,n);
	for(int i=n; i>=1; --i)
	{
		for(pii x: tag[i])
			tmn.update(1,1,pcnt,x.first,x.second);
		ans += tmn.mn[1] - i + 1;
	}
	printf("%lld",ans);
	return 0;
}