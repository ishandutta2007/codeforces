#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

int a[MAXN],b[MAXN*2];
int ans[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int flag=0;
	for(int i=1; i<n; ++i)
		if(a[i]==a[i+1]){ flag=i+1; break;}
	if(a[1]==a[n]) flag=1;
	
	if(!flag)
	{
		if(n&1)
			printf("3\n3 "),
			--n;
		else printf("2\n");
		
		for(int i=1; i<=n; ++i) printf("%d ",(i&1)+1);
		putchar('\n');
		return;
	}
	
	bool dif=0;
	for(int i=1; i<n; ++i)
		if(a[i]!=a[i+1]) dif=1;
	if(a[1]!=a[n]) dif=1;
	
	if(dif)
	{
		printf("2\n");
		for(int i=1; i<flag; ++i) printf("%d ",((i+n-flag)&1)+1);
		for(int i=flag; i<=n; ++i) printf("%d ",((i-flag)&1)+1);
		putchar('\n');
	}
	else
	{
		printf("1\n");
		for(int i=1; i<=n; ++i) printf("%d ",1);
		putchar('\n');
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}