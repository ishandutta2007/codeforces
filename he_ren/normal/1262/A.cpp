#include<cstdio>
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	int al=inf, ar=0;
	for(int i=1; i<=n; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		chk_min(al,r);
		chk_max(ar,l);
	}
	if(ar<al) printf("0\n");
	else printf("%d\n",ar-al);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}