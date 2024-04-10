#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 50 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	int cnt[2] = {0,0};
	for(int i=1; i<=n; ++i)
		++cnt[a[i]&1];
	
	if(cnt[0]%2 != cnt[1]%2){ printf("NO\n"); return;}
	if(cnt[0]%2 == 0){ printf("YES\n"); return;}
	
	for(int i=1; i<n; ++i)
		if(a[i]+1 == a[i+1])
		{
			printf("YES\n");
			return;
		}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}