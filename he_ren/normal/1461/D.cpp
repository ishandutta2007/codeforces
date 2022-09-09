#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];
ll sum[MAXN];

set<ll> t;
void split(int l,int r)
{
	t.insert(sum[r] - sum[l-1]);
	if(a[l] == a[r]) return;
	
	int mid = (a[l] + a[r]) / 2, pos = upper_bound(a+l,a+r+1,mid) - a;
	split(l, pos-1); split(pos, r);
}

void solve(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	t.clear();
	split(1,n);
	
	while(Q--)
	{
		int x;
		scanf("%d",&x);
		if(t.find(x) != t.end()) printf("Yes\n");
		else printf("No\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}