#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;
const int MAXM = 3e5 + 5;

ll a[MAXN],b[MAXM];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i) scanf("%lld",&b[i]);
	
	int ans=-1;
	ll sa=0, sb=0 ,i=1,j=1;
	while(1)
	{
		if(sa==sb)
		{
			sa=sb=0; ++ans;
			if(i>n && j>m){ printf("%d",ans); return 0;}
			if(i>n || j>m){ printf("-1"); return 0;}
			sa=a[i++];
			continue;
		}
		if(sa>sb)
		{
			if(j>m){ printf("-1"); return 0;}
			sb+=b[j++];
			continue;
		}
		if(sb>sa)
		{
			if(i>n){ printf("-1"); return 0;}
			sa+=a[i++];
			continue;
		}
	}
	return 0;
}