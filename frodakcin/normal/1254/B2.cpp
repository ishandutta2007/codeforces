#include <cstdio>
#include <cassert>
#include <algorithm>

using ll = long long;

const int MN = 1e6 + 10;
int N, a[MN], P;
ll S, p[60], ans=1e18;

int main(void)
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", a+i), S+=a[i];
	if(S <= 1) return printf("-1\n"), 0;
	for(ll d=2;d*d<=S;++d)
		if(S%d==0)
		{
			p[P++] = d;
			S/=d;
			while(S%d == 0) S/=d;
		}
	if(S>1)
		p[P++] = S;
	for(int x=0;x<P;++x)
	{
		ll p=::p[x];
		//printf("PR: %lld\n", p);
		ll t=0, v=0, c=a[0]%p;
		for(int i=0,j,k;i<N;)
		{
			if(c == 0)
			{
				c = a[++i]%p;
				continue;
			}
			v=c;
			for(k=i+1;k<N&&(c+=a[k])<p;++k);
			if(k==N) break;
			c=v;
			for(j=i;c*2<p;) t+=c, c+=a[++j];
			assert(j <= k);
			//printf("MED: %d\n", j);
			if(j<k)
			{
				for(i=j+1;i<k;++i) t+=(ll)a[i]*(i-j), c+=a[i];
				t+=(p-c)*(i-j);
				c+=a[i]-p;
			}
			else
				i=k;
			c%=p;
		}
		assert(!c);
		ans = std::min(ans, t);
	}
	printf("%lld\n", ans);
	return 0;
}