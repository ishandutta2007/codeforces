#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;

inline void chk_max(ll &a,ll b){ if(a<b) a=b;}

int n,rds;
ll m;
ll a[MAXN],b[MAXN];

bool chk(ll mid)
{
	for(int i=1; i<=n; ++i) b[i]=a[i];
	
	ll lft=m, now=0;
	for(int i=1; i<=n; ++i)
	{
		now+=b[i];
		if(now<mid)
		{
			ll ned = mid-now;
			if(ned>lft) return 0;
			lft-=ned;
			
			now+=ned;
			b[min(i+(rds<<1)+1, n+1)]-=ned;
		}
	}
	return 1;
}

int main(void)
{
	cin>>n>>rds>>m;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		a[max(i-rds, 1)]+=x;
		a[min(i+rds+1, n+1)]-=x;
	}
	
	ll Lb=0, Rb=0, now=0;
	for(int i=1; i<=n; ++i)
		now+=a[i], chk_max(Rb,now);
	Rb+=m;
	while(Lb<Rb)
	{
		ll Mid = (Lb+Rb+1)>>1ll;
		if(chk(Mid)) Lb=Mid;
		else Rb=Mid-1;
	}
	
	cout<<Lb;
	return 0;
}