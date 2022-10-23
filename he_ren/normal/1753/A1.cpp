#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	int sum = accumulate(a+1,a+n+1,0);
	if(sum % 2 != 0)
	{
		printf("-1\n");
		return;
	}
	
	int need = sum < 0? -1: 1;
	int rem = abs(sum) / 2;
	
	int tot = n;
	
	static bool is[MAXN];
	for(int i=1; i<=n+1; ++i)
		is[i] = 0;
	for(int i=2; i<=n && rem; ++i)
		if(a[i] == need)
		{
			is[i] = 1;
			i += 1;
			--rem;
			--tot;
		}
	
	if(rem)
	{
		printf("-1\n");
		return;
	}
	
	printf("%d\n",tot);
	for(int i=1; i<=n; ++i)
		if(!is[i])
		{
			if(is[i+1]) printf("%d %d\n",i,i+1);
			else printf("%d %d\n",i,i);
		}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}