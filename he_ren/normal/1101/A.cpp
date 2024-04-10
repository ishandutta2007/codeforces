#include<cstdio>
#include<algorithm>
using namespace std;

void solve(void)
{
	int l,r,d;
	scanf("%d%d%d",&l,&r,&d);
	if(d<l){ printf("%d\n",d); return;}
	if(r%d) printf("%d\n",r-r%d+d);
	else printf("%d\n",r+d);
}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}