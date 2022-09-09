#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int n;
int a[MAXN], b[MAXN];

inline bool chk(int k)
{
	if(k <= 1) return 1;
	vector<pii> p;
	int j = 1;
	for(int i=1; i<=n; ++i)
	{
		int r = min(k, b[i] + 1);
		int l = max(1, k - a[i]);
		if(l > r) continue;
		if(l <= j && j <= r) ++j;
	}
	return j > k;
}

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	
	int l = 1, r = n;
	while(l<r)
	{
		int mid = (l+r+1)>>1;
		if(chk(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}