#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXA = 2e5 + 5;

bool isnp[MAXA];
int p[MAXA],pcnt=0, pid[MAXA];
void sieve(int n)
{
	isnp[0]=isnp[1]=1;
	for(int i=2; i<=n; ++i)
		if(!isnp[i])
		{
			p[++pcnt] = i;
			pid[i] = pcnt;
			for(int j=i<<1; j<=n; j+=i)
				isnp[j] = 1;
		}
}

int mn[MAXA][2], cnt[MAXA];
inline void update_mn(int i,int x)
{
	++cnt[i];
	if(x <= mn[i][0] || !mn[i][0])
		mn[i][1] = mn[i][0],
		mn[i][0] = x;
	else if(x <= mn[i][1] || !mn[i][1])
		mn[i][1] = x;
}

int a[MAXN];

int main(void)
{
	sieve(2e5);
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
	{
		int sqa = sqrt(a[i]);
		for(int j=1; p[j]<=sqa && a[i]>1; ++j)
		{
			if(a[i]%p[j]) continue;
			
			int now = 1;
			while(!(a[i]%p[j]))
				a[i]/=p[j],
				now*=p[j];
			
			update_mn(j,now);
		}
		
		if(a[i]>1) update_mn(pid[a[i]], a[i]);
	}
	
	ll ans=1;
	for(int i=1; i<=pcnt; ++i)
	{
		if(cnt[i] == n) ans *= mn[i][1];
		else if(cnt[i] == n-1) ans *= mn[i][0];
	}
	printf("%lld",ans);
	return 0;
}