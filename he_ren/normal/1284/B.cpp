#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXA = 1e6 + 5;

int a[MAXN],b[MAXN],t[MAXA];

int main(void)
{
	int n;
	scanf("%d",&n);
	
	int m=0,cnt=0;
	ll ans=0;
	for(int i=1; i<=n; ++i)
	{
		int l;
		scanf("%d",&l);
		for(int j=1; j<=l; ++j) scanf("%d",&a[j]);
		
		bool flag=0;
		for(int j=1; j<l; ++j)
			if(a[j]<a[j+1])
			{
				++cnt;
				flag=1;
				break;
			}
		if(flag) continue;
		
		b[++m]=a[1];
		++t[a[l]];
	}
	
	for(int i=1; i<MAXA; ++i)
		t[i]+=t[i-1];
	for(int i=1; i<=m; ++i)
		if(b[i]) ans+=t[b[i]-1];
	
	ans += (ll)m*cnt*2 + (ll)cnt*cnt;
	
	printf("%lld",ans);
	return 0;
}