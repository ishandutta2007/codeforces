#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a > b) swap(a,b);
	printf("%d\n",(b-a + 10-1)/10);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}