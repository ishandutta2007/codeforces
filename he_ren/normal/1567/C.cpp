#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 10 + 5;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

char s[MAXN];

int f[10][2][2];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	reverse(s+1,s+n+1);
	
	int all = (1<<n) - 1;
	ll ans = 0;
	for(int mask=0; mask<=all; mask+=4)
	{
		ll cur = 1;
		for(int i=1; i<=n; ++i)
			cur *= f[s[i] - '0'][bdig(mask, i-1)][bdig(mask, i+1)];
		ans += cur;
	}
	
	printf("%lld\n",ans - 2);
}

int main(void)
{
	for(int i=0; i<10; ++i)
		for(int j=0; j<=1; ++j)
			for(int k=0; k<=1; ++k)
				for(int x=0; x<10; ++x)
				{
					int y = (i - x - j) % 10;
					if(y < 0) y += 10;
					if(k == (x + y + j >= 10))
						++f[i][j][k];
				}
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}