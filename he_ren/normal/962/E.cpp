#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void chk_max(int &a,int b){ if(a<b) a=b;}
inline void chk_max(ll &a,ll b){ if(a<b) a=b;}
inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

int main(void)
{
	int n;
	scanf("%d",&n);
	int lB=inf, lR=inf, lP=inf;
	int nB=0, nR=0;
	int mxB=0, mxR=0;
	ll ans=0;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		char c=getchar();
		while(c<'A'||c>'Z') c=getchar();
		
		if(c!='B')
		{
			if(lB!=inf)
				chk_max(mxB,x-lB),
				nB += x-lB;
			lB=x;
		}
		if(c!='R')
		{
			if(lR!=inf)
				chk_max(mxR,x-lR),
				nR += x-lR;
			lR=x;
		}
		if(c=='P')
		{
			ll tmp = (ll)nB+nR;
			if(lP!=inf) chk_min(tmp, x-lP + nB-mxB + nR-mxR);
			ans += tmp;
			nB=nR=0;
			mxB=mxR=0;
			lP=x;
		}
	}
	ans += (ll)nB+nR;
	printf("%lld",ans);
	return 0;
}