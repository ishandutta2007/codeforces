#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

inline void chk_max(ll &a,ll b){ if(a<b) a=b;}

int b[MAXN];
map<int,int> t;
ll f[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
	{
		f[i]=b[i];
		
		int j = t[i-b[i]];
		t[i-b[i]]=i;
		
		if(j) chk_max(f[i], f[j]+b[i]);
		chk_max(ans, f[i]);
	}
	printf("%lld",ans);
	return 0;
}