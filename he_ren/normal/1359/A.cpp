#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	int x = n/d;
	
	if(m<=x) printf("%d\n",m);
	else printf("%d\n",x - (m-x + d-2)/(d-1));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}