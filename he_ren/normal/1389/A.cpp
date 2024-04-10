#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int l,r;
	scanf("%d%d",&l,&r);
	if(l*2 > r) printf("-1 -1\n");
	else printf("%d %d\n",l,l*2);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}