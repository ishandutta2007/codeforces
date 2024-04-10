#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%lld\n",(ll)a+(ll)b+(ll)c-1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}