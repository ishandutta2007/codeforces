#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

void solve(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	if(a>b) swap(a,b);
	printf("%d\n",max(a*2,b) * max(a*2,b));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}