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
	if(a<b) swap(a,b);
	
	if(a >= b*2) printf("%d\n",b);
	else printf("%d\n",(a+b)/3);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}