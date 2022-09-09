#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;

inline int gcd(int a,int b){ return b? gcd(b,a%b): a;}

inline bool cmp(int x,int y){ return (x&1) < (y&1);}

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1,cmp);
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
			if(gcd(a[i], 2 * a[j]) > 1) ++ans;
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}