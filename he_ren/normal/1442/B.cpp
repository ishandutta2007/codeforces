#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int mod = 998244353;

int a[MAXN], b[MAXN];
int lef[MAXN], rig[MAXN];
inline void erase(int x)
{
	rig[lef[x]] = rig[x];
	lef[rig[x]] = lef[x];
}

bool has[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=d; ++i) scanf("%d",&b[i]);
	
	for(int i=1; i<=n; ++i) has[i] = 0;
	for(int i=1; i<=d; ++i) has[b[i]] = 1;
	has[0] = has[n+1] = 1;
	
	a[0] = 0; a[n+1] = n+1;
	rig[0] = a[1]; lef[n+1] = a[n+1];
	for(int i=1; i<=n; ++i)
		lef[a[i]] = a[i-1],
		rig[a[i]] = a[i+1];
	
	int ans = 1;
	for(int i=1; i<=d; ++i)
	{
		int x = b[i];
		
		if(has[lef[x]] && has[rig[x]]){ printf("0\n"); return;}
		
		if(has[lef[x]]) erase(rig[x]);
		else if(has[rig[x]]) erase(lef[x]);
		else
		{
			ans = ans * 2 %mod;
			erase(x);
		}
		
		has[x] = 0;
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