#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n,x,m;
	scanf("%d%d%d",&n,&x,&m);
	
	int L=x, R=x;
	for(int i=1; i<=m; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(max(l,L) > min(r,R)) continue;
		
		L = min(L,l); R = max(R,r);
	}
	printf("%d\n",R-L+1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}