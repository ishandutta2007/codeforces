#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int a[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int cnt = 1;
	for(int i=2; i<=n; ++i)
		if(a[i] != a[i-1]) ++cnt;
	
	if(d == 1) printf("%d\n",cnt == 1? 1: -1);
	else printf("%d\n",cnt < d? 1: 1 + (cnt-d + d-1 - 1)/(d-1));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}