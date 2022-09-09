#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	priority_queue<int> q;
	for(int i=1; i<=n; ++i) q.push(a[i]);
	
	int now = 1, lst = 0;
	while(!q.empty())
	{
		int x = q.top(); q.pop();
		if(lst) q.push(lst);
		lst = --x;
		now ^= 1;
	}
	if(now) printf("HL\n");
	else printf("T\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}