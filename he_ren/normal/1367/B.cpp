#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 40 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; ++i) scanf("%d",&a[i]);
	
	int cnt[2] = {0,0};
	for(int i=0; i<n; ++i)
		if(i%2 != a[i]%2) ++cnt[i%2];
	
	if(cnt[0] != cnt[1]) printf("-1\n");
	else printf("%d\n",cnt[0]);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}