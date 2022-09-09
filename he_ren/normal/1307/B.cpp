#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int a[MAXN];

void solve(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int mx=0;
	for(int i=1; i<=n; ++i)
	{
		if(mx<a[i]) mx=a[i];
		if(a[i]==x){ printf("1\n"); return;}
	}
	if(mx>x) printf("2\n");
	else printf("%d\n",(x+mx-1)/mx);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}