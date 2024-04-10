#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using ll = long long;
const int MV=1000;
const int MP=200;
const ll MX=1e9;
const ll MQ=1e18;

int p[MP], P, c[MV], nx[MV], ct[MV], ans, T, a;
void sieve()
{
	for(int i=2;i<MV;++i)
	{
		if(!c[i])
			p[P++]=i;
		for(int j=0,k;j<P && (k=i*p[j])<MV;++j)
		{
			assert(!c[k]);
			c[k]=1;
			nx[k]=i, ct[k]=1;
			if(i%p[j]==0)
				break;
		}
	}
}

std::vector<int> pf;
int main(void)
{
	sieve();
	scanf("%d", &T);
	for(;T--;)
	{
		for(int i=0,j;i<40;++i)
		{
			ll g=1;
			for(j=i;j<40;++j)
				if(g<=MQ/p[j])
					g*=p[j];
				else
					break;
			printf("? %lld\n", g);
			fflush(stdout);
			scanf("%d", &a);
			for(;i<j;++i)
				if(a%p[i]==0)
					pf.push_back(p[i]);
		}
		int v=1;
		ans=1;
		for(int i=0;i<pf.size();++i)
		{
			ll g=1, q=1;
			for(;g<MX/pf[i];)
				g*=pf[i];
			q*=g;
			++i;
			if(i<pf.size())
			{
				g=1;
				for(;g<MX/pf[i];)
					g*=pf[i];
				q*=g;
			}

			printf("? %lld\n", q);
			fflush(stdout);
			scanf("%d", &a);
			v*=a;
			int c=1;
			while(a%pf[i-1]==0)
				a/=pf[i-1], ++c;
			ans*=c;
			if(i<pf.size())
			{
				c=1;
				while(a%pf[i]==0)
					a/=pf[i], ++c;
				ans*=c;
			}
		}

		if(v <= 3)
			printf("! 8\n");
		else
		{
			//v*p**3 <= MX
			//we only need to catch if there are 3 others, and if so we only need to catch one of the three
			int mv=MX/v;
			ll g;
			for(int i=40,j;(ll)p[i]*p[i]*p[i]<=mv;)
			{
				g=1;
				for(j=i;(ll)p[j]*p[j]*p[j]<=mv;++j)
					if(g<=MQ/p[j])
						g*=p[j];
					else
						break;
				printf("? %lld\n", g);
				fflush(stdout);
				scanf("%lld", &g);
				for(;i<j;++i)
					if(g%p[i]==0)
						ans*=2;
			}
			printf("! %d\n", ans*2);
		}
		pf.clear();
	}
	return 0;
}