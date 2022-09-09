#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int lb = 62;

#define bit(x,i) (((x)>>(i))&1)

ll m;
int n,a[MAXN];
int cnt[70],t[70];
ll rem;

bool gao(int i)
{
	if(i>lb) return 0;
	if(t[i]){ --t[i]; return 1;}
	if(!rem) return 0;
	--rem;
	if(gao(i+1))
	{
		++t[i];
		return 1;
	}
	return 0;
}

bool chk(ll mid)
{
	rem=mid;
	for(int i=0; i<=lb; ++i) t[i]=cnt[i];
	
	for(int i=0; i<=lb; ++i)
	{
		if(bit(m,i) && !gao(i)) return 0;
		t[i+1] += t[i]>>1;
		t[i]&=1; 
	}
	return 1;
}

void solve(void)
{
	scanf("%lld%d",&m,&n);
	ll sum=0;
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]), sum+=a[i];
	
	if(sum<m){ printf("-1\n"); return;}
	
	memset(cnt,0,sizeof(cnt));
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<=31; ++j)
			if(bit(a[i],j))
			{
				++cnt[j];
				break;
			}
	}
	
	ll l=0, r=1e18;
	while(l<r)
	{
		ll mid = (l+r)>>1ll;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}