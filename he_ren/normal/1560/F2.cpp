#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXM = 9 + 5;
const int ALL = (1<<10) + 5;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

int lb[ALL], num1[ALL];

char s[MAXM];
int a[MAXM];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	sprintf(s+1,"%d",n);
	int m = strlen(s+1);
	for(int i=1; i<=m; ++i) a[i] = s[i] - '0';
	
	if((int)set<int>(a+1,a+m+1).size() <= d)
	{
		printf("%d\n",n);
		return;
	}
	
	ll ans = 1111111111ll;
	int all = (1<<10) - 1;
	for(int mask=1; mask<=all; ++mask) if(num1[mask] <= d)
	{
		int pos = -1, val;
		for(int i=1; i<=m; ++i)
		{
			int x = a[i], rem = mask & (all << x);
			if(rem)
			{
				if(rem != bbit(a[i])) pos = i, val = rem & (all ^ bbit(a[i]));
				if((rem & bbit(a[i])) == 0)
				{
					ll cur = 0;
					for(int j=1; j<i; ++j) cur = cur * 10 + a[j];
					cur = cur * 10 + lb[lowbit(rem)];
					for(int j=i+1; j<=m; ++j)
						cur = cur * 10 + lb[lowbit(mask)];
					ans = min(ans, cur);
					break;
				}
			}
			else
			{
				if(pos == -1) break;
				ll cur = 0;
				for(int j=1; j<pos; ++j) cur = cur * 10 + a[j];
				cur = cur * 10 + lb[lowbit(val)];
				for(int j=pos+1; j<=m; ++j)
					cur = cur * 10 + lb[lowbit(mask)];
				ans = min(ans, cur);
				break;
			}
		}
	}
	printf("%lld\n",ans);
}

int main(void)
{
	lb[0] = -1;
	for(int i=2; i<ALL; ++i) lb[i] = lb[i>>1] + 1;
	for(int i=1; i<ALL; ++i) num1[i] = num1[i^lowbit(i)] + 1;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}