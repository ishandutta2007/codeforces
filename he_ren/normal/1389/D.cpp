#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,d,l1,r1,l2,r2;
	scanf("%d%d%d%d%d%d",&n,&d,&l1,&r1,&l2,&r2);
	
	ll len = (ll)max(min(r1,r2) - max(l1,l2), 0) * n;
	if(len >= d){ printf("0\n"); return;}
	d -= len;
	
	ll need = max(max(l1,l2) - min(r1,r2), 0);
	ll full = max(r1,r2) - min(l1,l2) - max(min(r1,r2) - max(l1,l2), 0);
	
	if(full >= d){ printf("%lld\n",need + min((ll)d,full)); return;}
	if(full <= need)
	{
		d -= full;
		printf("%lld\n", need + full + d * 2);
		return;
	}
	else
	{
		ll use;
		if(!full) use = n;
		else use = min(d/full, (ll)n);
		
		ll ans = use * (need + full);
		d -= use * full;
		
		ll tmp = d * 2;
		if(use < n) tmp = min(tmp, need + d);
		printf("%lld\n",ans+tmp);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}