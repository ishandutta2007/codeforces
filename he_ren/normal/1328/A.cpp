#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a%b==0) printf("%d\n",0);
	else printf("%d\n",b-a%b);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}