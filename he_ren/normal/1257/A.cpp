#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,x,a,b;
	scanf("%d%d%d%d",&n,&x,&a,&b);
	if(a>b) swap(a,b);
	
	int tmp = min(x,a-1);
	a -= tmp; x -= tmp;
	
	tmp = min(x,n-b);
	b += tmp; x -= tmp;
	
	printf("%d\n",b-a);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}