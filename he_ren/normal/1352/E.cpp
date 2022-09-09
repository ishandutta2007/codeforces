#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 8e3 + 5;
const int MAXA = MAXN;

int a[MAXN],sum[MAXN];
bool t[MAXA];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) sum[i] = sum[i-1] + a[i];
	
	for(int i=1; i<=n; ++i) t[i]=0;
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
		{
			int x = sum[j]-sum[i-1];
			if(x<=n) t[x]=1;
		}
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		if(t[a[i]]) ++ans;
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}