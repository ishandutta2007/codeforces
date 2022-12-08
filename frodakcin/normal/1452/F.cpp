#include <cstdio>
#include <cassert>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MN = 40;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int N, Q, cnt[MN];

ll cost(int n, ll k)
{
	if(k==1ll<<n) return (1ll<<n+1)-1;
	if(k==0) return 0;
	assert(n>0);
	if(k<1ll<<n-1) return 1+cost(n-1, k);
	else return (1ll<<n)+cost(n-1, k-(1ll<<n-1));
}

int main()
{
	scanf("%d%d", &N, &Q);
	for(int i=0;i<N;++i)
		scanf("%d", cnt+i);

	for(int i=0;i<Q;++i)
	{
		int t;
		scanf("%d", &t);
		if(t==1)
		{
			int pos;
			scanf("%d", &pos);
			scanf("%d", cnt+pos);
		}
		else
		{
			//hard part
			int x;
			ll k;
			scanf("%d%lld", &x, &k);
			ll cur=0, tot=0, ans=0;
			for(int i=0;i<=x;++i)
				cur += cnt[i], tot += (ll)cnt[i]<<i;

			if(k<=cur)
			{
				printf("0\n");
				continue;
			}
			for(int i=1;x+i<N;++i)
			{
				int use=(int)std::min<ll>(cnt[x+i], (k-cur)>>i);
				cur+=use*(1ll<<i), tot+=(ll)use<<i+x, ans+=use*((1ll<<i)-1);
				if(cnt[x+i]>use) // you have spare !
				{
					if(tot>=k)
						break;

					//0 < k-tot <= k-cur < 2^i
					int must=(int)(k-tot+(1<<x+1)-1>>x+1);
					//k-tot <= (k-cur) < 2^{x+i} [otherwise, ++use]
					assert(0 < must && must <= 1<<i-1);
					int spare=0;
					for(int j=i;j>1;--j)
						if(must>1<<j-2) // go to RHS
						{
							must -= 1<<j-2;
							cur += 1ll<<j-1;
							tot += 1ll<<j-1+x;
							ans += 1ll<<j-1;
						}
						else
						{
							spare |= 1<<j-1;
							ans += 1;
						}
					assert(must == 1);
					if(must>0)
					{
						cur += 2ll;
						tot += 2ll<<x;
						ans += 1ll;
						--must;
					}
					assert(tot >= k);

					for(int j=0;j<N;++j)
						if(spare>>j&1 && cur+(1<<j)<=k)
							cur+=1<<j, ans += (1<<j)-1;

					break;
				}
			}

			if(tot < k)
			{
				printf("-1\n");
				continue;
			}
			printf("%lld\n", k <= cur ? ans : ans+k-cur);
		}
	}
	return 0;
}