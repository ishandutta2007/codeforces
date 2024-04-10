#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 20 + 5;

char s[MAXN], t[MAXN];
inline int get_res(void)
{
	int n = strlen(s+1), m = strlen(t+1);
	int pos = 1;
	for(int i=1; i<=n && pos<=m; ++i)
		if(s[i] == t[pos]) ++pos;
	--pos;
	return n - pos + m - pos;
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	sprintf(s+1,"%d",n);
	int ans = 1e9;
	for(int i=0; i<=60; ++i)
	{
		sprintf(t+1,"%lld",1ll<<i);
		ans = min(ans, get_res());
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