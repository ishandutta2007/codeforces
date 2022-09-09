#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int MAXC = 1e6 + 5;

int a[MAXN];
int bak[MAXC], sum[MAXC];

void solve(void)
{
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	memset(bak, 0, (c+1)<<2);
	for(int i=1; i<=n; ++i) bak[a[i]] = 1;
	for(int i=1; i<=c; ++i) sum[i] = bak[i] + sum[i-1];
	
	bool ok = 1;
	for(int i=1; i<=c && ok; ++i) if(bak[i])
		for(int j=i, t=1; j<=c && ok; j+=i, ++t)
		{
			int k = min(c, j+i-1);
			if(sum[k] - sum[j-1])
			{
				if(bak[t] == 0)
				{
					ok = 0;
				}
			}
		}
	printf(ok? "Yes\n": "No\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}