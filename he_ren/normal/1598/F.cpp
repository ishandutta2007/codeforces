#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 20 + 5;
const int ALL = (1<<20) + 5;
const int inf = 0x3f3f3f3f;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

string s[MAXN];
int a[MAXN], b[MAXN];
vector<int> val[MAXN];

int f[ALL];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) cin >> s[i];
	
	for(int i=1; i<=n; ++i)
	{
		int cnt = 0;
		for(char c: s[i])
		{
			if(c == '(') ++a[i];
			else
			{
				if(a[i])
				{
					--a[i];
					if(a[i] == 0) ++cnt;
				}
				else
				{
					++b[i];
					val[i].push_back(cnt);
					cnt = 0;
				}
			}
		}
		val[i].push_back(cnt);
	}
	
	int all = (1<<n) - 1;
	memset(f, 0xc0, sizeof(f));
	f[0] = 0;
	int ans = 0;
	for(int mask=0; mask<=all; ++mask)
	{
		if(f[mask] < 0) continue;
		ans = max(ans, f[mask]);
		int sum = 0;
		for(int i=1; i<=n; ++i) if(bdig(mask, i-1))
			sum = sum - b[i] + a[i];
//		printf("mask = %d, f = %d\n",mask,f[mask]);
		assert(sum >= 0);
		
		for(int i=1; i<=n; ++i) if(!bdig(mask, i-1))
		{
			int nxt = f[mask];
			if(sum <= b[i])
			{
				nxt += val[i][sum] + (sum != 0);
				ans = max(ans, nxt);
			}
			if(sum >= b[i])
				f[mask | bbit(i - 1)] = max(f[mask | bbit(i - 1)], nxt);
		}
	}
	
	printf("%d",ans);
	return 0;
}