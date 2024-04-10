#include<cstdio>
#include<algorithm>
using namespace std;

void solve(void)
{
	int a,b,c,rds;
	scanf("%d%d%d%d",&a,&b,&c,&rds);
	int l=c-rds, r=c+rds;
	if(a>b) swap(a,b);
	
	int L=max(a,l), R=min(b,r);
	int len = R-L;
	if(len<0) len=0;
	printf("%d\n",b-a-len);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}