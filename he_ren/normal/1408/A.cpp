#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int a[MAXN], b[MAXN], c[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	
	static int p[MAXN];
	p[1] = p[n+1] = a[1];
	for(int i=2; i<n; ++i)
		if(a[i] == p[i-1])
			p[i] = b[i];
		else p[i] = a[i];
	
	static bool fob[105];
	fob[p[n-1]] = 1;
	fob[p[1]] = 1;
	
	if(!fob[a[n]]) p[n] = a[n];
	if(!fob[b[n]]) p[n] = b[n];
	if(!fob[c[n]]) p[n] = c[n];
	
	fob[p[n-1]] = 0;
	fob[p[1]] = 0;
	
	for(int i=1; i<=n; ++i)
		printf("%d ",p[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}