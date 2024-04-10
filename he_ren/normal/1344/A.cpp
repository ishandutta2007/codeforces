#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

int a[MAXN];
int t[MAXN*5];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; ++i) scanf("%d",&a[i]);
	
	for(int i=0; i<n; ++i)
		a[i] %= n;
	
	int m = 5*n;
	for(int i=0; i<m; ++i) t[i] = 0;
	for(int i=0; i<m; ++i)
	{
		int x = i + a[i%n];
		if(x>=0 && x<m) ++t[x];
	}
	
	for(int i=2*n; i<3*n; ++i)
		if(t[i]!=1){ printf("No\n"); return;}
	printf("Yes\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}