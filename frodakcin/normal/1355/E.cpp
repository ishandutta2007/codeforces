#include <cstdio>
#include <algorithm>

using ll=long long;
const int MN=1e5+10;
const ll INF=4e18;

int N, A, R, M, a[MN];
ll fans=INF, ans, dec, inc;

ll get(ll u, ll v)
{
		if(v>u) return u*M+(v-u)*R;
		else return v*M+(u-v)*A;
}
int main(void)
{
	scanf("%d%d%d%d", &N, &A, &R, &M);
	for(int i=0;i<N;++i)
		scanf("%d", a+i), dec+=a[i];
	std::sort(a, a+N);
	if(M>A+R)M=A+R;
	else
	{
		ll x=dec/N, v=0, u=0, y=(dec+N-1)/N;
		for(int i=0;i<N;++i)
			if(a[i]<x)
				u+=x-a[i];
			else
				v+=a[i]-x;
		ans=get(u,v);
		if(ans<fans)fans=ans;
		if(y>x)
		{
			u=v=0;
			for(int i=0;i<N;++i)
				if(a[i]<y)
					u+=y-a[i];
				else
					v+=a[i]-y;
			ans=get(u,v);
			if(ans<fans)fans=ans;
		}
	}
	dec-=a[0]*(ll)N;
	for(int i=0;i<N;++i)
	{
		ans=get(inc, dec);
		if(ans<fans) fans=ans;
		if(i+1<N)
			inc+=(ll)(a[i+1]-a[i])*(i+1), dec-=(ll)(a[i+1]-a[i])*(N-i-1);
	}
	printf("%lld\n", fans);
	return 0;
}