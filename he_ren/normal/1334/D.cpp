#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int n;
ll l,r;
inline void print(int x,ll pos){ if(pos>=l && pos<=r) printf("%d ",x);}

void solve(void)
{
	scanf("%d%lld%lld",&n,&l,&r);
	
	if(l == (ll)n*(n-1)+1)
	{
		printf("1\n");
		return;
	}
	
	bool flag=0;
	if(r == (ll)n*(n-1)+1) flag=1, --r;
	
	int now=0;
	ll tot=0;
	while(tot<l)
		++now, tot += 2*(n-now);
	
	ll pos = tot - 2*(n-now);
	for(int i=1; pos<=r;)
	{
		print(now,++pos);
		print(now+i,++pos);
		
		if(now+i==n)
		{
			++now;
			i=1;
		}
		else ++i;
	}
	
	if(flag) printf("1 ");
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}