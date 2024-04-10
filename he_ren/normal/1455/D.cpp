#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;

int a[MAXN];

void solve(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int k=0; k<=n; ++k)
	{
		static int tmpa[MAXN], tmpx;
		for(int i=1; i<=n; ++i) tmpa[i] = a[i];
		tmpx = x;
		
		int cnt = 0;
		for(int i=1; i<=n && cnt < k; ++i)
			if(a[i] > x) swap(a[i], x), ++cnt;
		
		bool ok = 1;
		for(int i=2; i<=n; ++i)
			if(a[i] < a[i-1]){ ok = 0; break;}
		if(ok){ printf("%d\n",k); return;}
		
		for(int i=1; i<=n; ++i) a[i] = tmpa[i];
		x = tmpx;
	}
	printf("-1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}