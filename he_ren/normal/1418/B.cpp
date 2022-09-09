#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1e2 + 5;

int a[MAXN], l[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&l[i]);
	
	vector<int> b;
	for(int i=1; i<=n; ++i)
		if(!l[i]) b.push_back(a[i]);
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	
	for(int i=1,j=0; i<=n; ++i)
		printf("%d ",l[i]? a[i]: b[j++]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}