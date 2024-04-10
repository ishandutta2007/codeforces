#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

ll ans;
int p[MAXN];

void upd(int i,int k)
{
	if(p[i] > p[i-1])
		ans += k * (p[i] - p[i-1]);
}

void solve(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i)
		scanf("%d",&p[i]);
	p[n+1] = 0;
	
	ans = 0;
	for(int i=1; i<=n; ++i)
		if(p[i] > p[i-1]) ans += p[i] - p[i-1];
	printf("%lld\n",ans);
	
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(l>r) swap(l,r);
		if(l == r){ printf("%lld\n",ans); continue;}
		if(l == r-1)
		{
			upd(l,-1); upd(r+1,-1);
			upd(r,-1);
			
			swap(p[l],p[r]);
			
			upd(r,1);
			upd(l,1); upd(r+1,1);
			
			printf("%lld\n",ans);
			continue;
		}
		
		upd(l+1,-1); upd(r+1,-1);
		upd(l,-1); upd(r,-1);
		
		swap(p[l],p[r]);
		
		upd(l+1,1); upd(r+1,1);
		upd(l,1); upd(r,1);
		
		printf("%lld\n",ans);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}