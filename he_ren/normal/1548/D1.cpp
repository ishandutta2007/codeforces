#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 6e3 + 5;

int a[MAXN], b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	
	for(int i=1; i<=n; ++i) a[i] = (a[i] / 2) % 2, b[i] = (b[i] / 2) % 2;
	
	static int cnt[2][2];
	ll ans = 0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=i+1; j<=n; ++j)
		{
			if(a[j] == a[i] && b[j] == b[i]) ans += i-1;
			else ans += cnt[a[i]][b[i]] + cnt[a[j]][b[j]];
		}
		++cnt[a[i]][b[i]];
	}
	
	printf("%lld",ans);
	return 0;
}