#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int cnt[2] = {0,0};
	for(int i=1; i<=n; ++i)
		++cnt[a[i]];
	
	if(cnt[1] <= cnt[0])
	{
		printf("%d\n",cnt[0]);
		while(cnt[0]--) printf("0 ");
		putchar('\n');
		return;
	}
	
	if(cnt[1] & 1) --cnt[1];
	printf("%d\n",cnt[1]);
	while(cnt[1]--) printf("1 ");
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}