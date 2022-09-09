#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int d[MAXN], h[MAXN];

void solve(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1; i<=n; ++i) scanf("%d%d",&d[i],&h[i]);
	
	int mxd = 0;
	for(int i=1; i<=n; ++i)
		mxd = max(mxd, d[i]);
	if(x <= mxd){ printf("1\n"); return;}
	
	int mxdif = 0;
	for(int i=1; i<=n; ++i)
		mxdif = max(mxdif, d[i] - h[i]);
	if(!mxdif){ printf("-1\n"); return;}
	
	printf("%d\n",(x-mxd + mxdif-1)/mxdif + 1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}