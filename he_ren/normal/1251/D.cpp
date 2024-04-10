#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const ll inf = 1e14 + 5;

inline ll min(ll a,ll b){ return a<b? a: b;}

struct Node
{
	int l,r;
}a[MAXN];
inline bool cmp_l(const Node &p,const Node &q){ return p.l<q.l;}

int n;
ll s;
bool chk(int mid)
{
	int cntl=n>>1, cntr=(n+1)>>1;
	ll res=0;
	for(int i=1; i<=n; ++i)
	{
		if(a[i].r<mid)
		{
			--cntl;
			if(cntl<0) return 0;
			res += a[i].l;
		}
		else if(a[i].l>mid)
		{
			--cntr;
			if(cntr<0) return 0;
			res += a[i].l;
		}
		if(res > s) return 0;
	}
	for(int i=1; i<=n; ++i)
		if(a[i].l<=mid && mid<=a[i].r)
		{
			if(cntl)
			{
				--cntl;
				res += a[i].l;
			}
			else
			{
				--cntr;
				res += mid;
			}
			if(res > s) return 0;
		}
	return 1;
}

void solve(void)
{
	cin>>n>>s;
	for(int i=1; i<=n; ++i)
		cin>>a[i].l>>a[i].r;
	
	sort(a+1,a+n+1,cmp_l);
	int l=a[(n>>1)+1].l, r=1e9;
	while(l<r)
	{
		int mid = (l+r+1)>>1;
		if(chk(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}