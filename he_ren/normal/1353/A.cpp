#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	if(n==1) printf("0\n");
	if(n==2) printf("%d\n",m);
	if(n>2) printf("%d\n",m<<1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}