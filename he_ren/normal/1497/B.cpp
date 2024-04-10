#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

int a[MAXN], t[MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	memset(t,0,m<<2);
	for(int i=1; i<=n; ++i) ++t[a[i] % m];
	
	int ans = 0;
	for(int i=0; i<m; ++i)
	{
		int j = i? m-i: 0;
		if(j <= i)
		{
			if(t[i] && t[i] == t[j]) ++ans;
			else ans += max(t[i], t[j]) - min(t[i], t[j]);
		}
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}