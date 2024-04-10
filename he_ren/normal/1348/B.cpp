#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

int a[MAXN];

int t[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) t[i]=0;
	int cnt=0;
	for(int i=1; i<=n; ++i)
	{
		if(!t[a[i]])
			t[a[i]]=1, ++cnt;
	}
	if(cnt>d){ printf("-1\n"); return;}
	
	for(int i=1; i<=n && cnt<d; ++i)
		if(!t[i]) t[i]=1, ++cnt;
	
	printf("%d\n",n*d);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			if(t[j]) printf("%d ",j);
	putchar('\n');
	
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}